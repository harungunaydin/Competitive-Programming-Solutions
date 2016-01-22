#include <iostream>
#include <cstdio>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define MAXN 101
#define MAXK 10001
#define MOD 100000007
using namespace std;
int A[MAXN],T[MAXK];
int DP[2][MAXK];
void solve()
{
	int K,N,cur(0),i,j,k,pre;
	scanf("%d %d",&N,&K);
	FOR(i,1,N) scanf("%d",A+i);

	DP[0][0] = 1;

	FOR(i,1,K) DP[0][i] = 0;

	FOR(i,1,N)
	{
		pre = cur;
		cur ^= 1;
		FOR(j,0,K)
			DP[cur][j] = T[j] = ( ( (j >= A[i]) ? T[j-A[i]] : 0 ) + DP[pre][j] ) % MOD;
	}

	printf("%d\n" , DP[cur][K] );
}
int main()
{
	int T,i;
	scanf("%d",&T);
	FOR(i,1,T)
	{
		printf("Case %d: ",i);
		solve();
	}
	return 0;
}
