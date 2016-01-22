#include <cstdio>
#include <cstring>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define MAXN 202
using namespace std;
int M,N,Q;
long long D;
long long A[MAXN];
long long DP[MAXN][11][21];
long long dp(int x,int m,int d)
{
	long long &ret = DP[x][m][d];
	if(ret != -1) return ret;

	if(!m) return ret = !d;
	if(x == N + 1) return ret = 0;
	
	return ret = dp(x+1,m,d) + dp(x+1,m-1,(d + A[x] + D * (1000000000000LL) )%D);
}
void solve()
{
	int i;
	scanf("%d %d",&N,&Q);
	FOR(i,1,N) scanf("%lld",A+i);
	FOR(i,1,Q)
	{
		memset( DP , -1 , sizeof DP );
		scanf("%lld %d",&D,&M);
		printf("%lld\n" , dp(1,M,0) );
	}
}
int main()
{
	int T,i;
	scanf("%d",&T);
	FOR(i,1,T)
	{
		printf("Case %d:\n",i);
		solve();
	}
	return 0;
}
