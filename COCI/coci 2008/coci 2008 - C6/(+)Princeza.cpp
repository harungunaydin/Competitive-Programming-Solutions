#include <iostream>
#include <algorithm>
#include <cstdio>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define f first
#define s second
#define sag first
#define sol second
#define MAXN 100000
using namespace std;
typedef pair < int , int > pii;
typedef pair < pii , int > piii;
piii P2[MAXN+5];
pii A[MAXN+5],B[MAXN+5],P[MAXN+5];
int K,N;
char str[MAXN+5];
bool cmp( const piii &a , const piii &b )
{
	if(a.f.f - a.f.s < b.f.f - b.f.s) return 1;
	if(a.f.f - a.f.s > b.f.f - b.f.s) return 0;
	return a.f.s < b.f.s;
}
bool cmp2( const piii &a , const piii &b )
{
	if(a.f.f + a.f.s < b.f.f + b.f.s) return 1;
	if(a.f.f + a.f.s > b.f.f + b.f.s) return 0;
	return a.f.s < b.f.s;
}
void init()
{
	int i;
	FOR(i,1,N) P2[i] = make_pair(P[i],i);
	sort(P2+1,P2+N+1,cmp);
	FOR(i,1,N-1)
		if(P2[i].f.f - P2[i].f.s == P2[i+1].f.f - P2[i+1].f.s)
		{
			A[P2[i].s].sag = P2[i+1].s;
			A[P2[i+1].s].sol = P2[i].s;
		}
	sort(P2+1,P2+N+1,cmp2);
	FOR(i,1,N-1)
		if(P2[i].f.f + P2[i].f.s == P2[i+1].f.f + P2[i+1].f.s)
		{
			B[P2[i].s].sag = P2[i+1].s;
			B[P2[i+1].s].sol = P2[i].s;
		}
}
void read()
{
	int i;
	scanf("%d %d",&N,&K);
	scanf("%s",str);
	FOR(i,1,N)
		scanf("%d %d",&P[i].f,&P[i].s);
}
void sil(int x)
{
	A[A[x].sag].sol = A[x].sol; A[A[x].sol].sag = A[x].sag;
	B[B[x].sag].sol = B[x].sol; B[B[x].sol].sag = B[x].sag;
}
void solve()
{
	int cur(1),i;
	FOR2(i,K)
		switch(str[i])
		{
			case 'A' : if(A[cur].sag) { sil(cur); cur = A[cur].sag; } break;
			case 'B' : if(B[cur].sol) { sil(cur); cur = B[cur].sol; } break;
		  case 'C' : if(B[cur].sag) { sil(cur); cur = B[cur].sag; } break;
			case 'D' : if(A[cur].sol) { sil(cur); cur = A[cur].sol; } break;
		}
	printf("%d %d\n",P[cur].f,P[cur].s);
}
int main()
{
	read();
	init();
	solve();
	return 0;
}
