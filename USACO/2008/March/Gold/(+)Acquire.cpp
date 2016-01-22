#include <iostream>
#include <algorithm>
#include <cstdio>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define TFOR(i,a,b) for(i=a; i>=b; i--)
#define f first
#define s second
#define MAXN 50001
using namespace std;
typedef pair < int , int > pii;
typedef pair < long long , long long > pll;
pll D[MAXN],sta[MAXN];
pii A[MAXN],B[MAXN];
int K,M,N;
inline double inter_x(pll l1 , pll l2 ) { return (double) (l1.s - l2.s) / (l2.f - l1.f); }
void trick(long long m,long long n)
{
	pll l = make_pair(m,n);
	while(K > 1 && inter_x(l,sta[K-2]) < inter_x(sta[K-1],sta[K-2])) K--;
	sta[K++] = make_pair(m,n);
}
int BS(int bas,int son,int x)
{
	int orta = (bas + son) / 2;
	if(orta == K - 1) return orta;
	if(!orta) return x < inter_x(sta[0],sta[1]) ? 0 : 1;
	double x1 = inter_x(sta[orta-1],sta[orta]);
	double x2 = inter_x(sta[orta],sta[orta+1]);
	if(x1 <= x && x <= x2) return orta;
	return (x < x1) ? BS(bas,orta-1,x) : BS(orta+1,son,x);
}
void solve()
{
	long long t;
	int i,j;
	scanf("%d",&M);
	FOR(i,1,M) scanf("%d %d",&B[i].f,&B[i].s);
	sort(B+1,B+M+1);
	TFOR(i,M,1)
	{
		j = i;
		A[++N] = B[i];
		while( i >= 1 && B[i].s <= B[j].s ) i--;
		i++;
	}
	reverse(A+1,A+N+1);
	M = t = 0;
	FOR(i,1,N)
	{
		trick(A[i].s,t);
		t = BS(0,K-1,A[i].f);
		t = sta[t].f * A[i].f + sta[t].s;
	}
	printf("%lld\n" , t );
}
int main()
{
	solve();
	return 0;
}
