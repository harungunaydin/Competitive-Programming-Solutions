#include <cstdio>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define MAXN 15001
#define MOD 100000007
using namespace std;
int T[MAXN];
int DP[2][MAXN];
void solve()
{
	register int K,N,S,cur(0),i,j,k,m,pre(1),t;
	scanf("%d %d %d",&N,&K,&S);
	FOR(i,0,S) T[i] = 1;
	FOR(i,1,N)
	{
		pre = cur;
		cur = !cur;
		DP[cur][0] = 0;
		FOR(j,1,S)
			DP[cur][j] = ( ( T[j-1] + MOD ) - ( j > K ? T[j-K-1] : 0 ) ) % MOD;
		T[0] = 0;
		FOR(j,1,S)
			T[j] = ( T[j-1] + DP[cur][j] ) % MOD;
	}
	printf("%d\n" , DP[cur][S] % MOD );
}
int main()
{
	register int T,i;
	scanf("%d",&T);
	FOR(i,1,T)
	{
		printf("Case %d: ",i);
		solve();
	}
	return 0;
}
