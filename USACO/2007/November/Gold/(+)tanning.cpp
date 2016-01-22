#include <iostream>
#include <algorithm>
#include <cstdio>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define f first
#define s second
#define MAXN 2501
using namespace std;
typedef pair < int , int > pii;
bool cmp( const pii &a , const pii &b ) { return a.s < b.s || (a.s == b.s && a.f < b.f); }
pii A[MAXN],B[MAXN];
int M,N;
bool hash[MAXN];
void solve()
{
	int a,i,j,k,s(0);
	scanf("%d %d",&N,&M);
	FOR(i,1,N)
		scanf("%d %d",&A[i].f,&A[i].s);
	sort(A+1,A+N+1,cmp);
	FOR(i,1,M)
		scanf("%d %d",&B[i].f,&B[i].s);
	sort(B+1,B+M+1);
	FOR(i,1,M)
		FOR(k,1,N)
			if(!hash[k] && B[i].s && A[k].f <= B[i].f && B[i].f <= A[k].s)
			{
				hash[k] = true;
				B[i].s--;
				s++;
			}
	printf("%d\n" , s);
}
int main()
{
	solve();
	return 0;
}
