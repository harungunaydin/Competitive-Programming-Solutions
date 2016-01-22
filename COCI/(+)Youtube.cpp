#include <iostream>
#include <cstdio>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define MAXN 100000
using namespace std;
int K,M,N;
int A[MAXN+5],next[MAXN+5],tmp[MAXN+5];
void solve()
{
	int i;
	scanf("%d %d %d",&N,&K,&M);
	FOR(i,1,N) scanf("%d",A+i);
	FOR(i,1,K) scanf("%d",next+i);
	for(M--; M; M >>= 1)
	{
		if(M&1)
			FOR(i,1,N)
				A[i] = next[A[i]];
		FOR(i,1,K)
			tmp[i] = next[ next[i] ];
		FOR(i,1,K)
			next[i] = tmp[i];
	}
	FOR(i,1,N) printf("%d%c", A[i], i==N ? '\n' : ' ' );
}
int main()
{
	solve();
	return 0;
}
