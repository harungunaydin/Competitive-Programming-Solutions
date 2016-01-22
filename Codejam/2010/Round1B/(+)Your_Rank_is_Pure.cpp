#include <cstdio>
#include <cstring>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define MAXN 505
#define MOD 100003
using namespace std;
long long C_DP[MAXN][MAXN],DP[MAXN][MAXN];
long long C(int n,int r)
{
	long long &ret = C_DP[n][r];
	if(ret != -1) return ret;
	if(n < r || n < 0 || r < 0) return ret = 0;
	if(n == r || !r || n == 1) return ret = 1;
	return ret = ( C(n-1,r-1) + C(n-1,r) ) % MOD;
}
long long dp(int n,int k)
{
	long long &ret = DP[n][k];
	if(ret != -1) return ret;
	if(n == 1) return ret = 1;
	ret = 0;
	for(int i = 1; i < n; i++)
		ret = ( ret + dp(i,n) * C(k-n-1,n-i-1) ) % MOD;
	return ret;
}
int main()
{
	freopen("inp","r",stdin);
	freopen("out","w",stdout);
	memset( C_DP , -1 , sizeof C_DP );
	int T,i,j,n,res;
	scanf("%d",&T);
	FOR(i,1,T)
	{
		memset( DP , -1 , sizeof DP );
		scanf("%d",&n);
		res = 0;
		FOR(j,1,n-1)
			res = ( res + dp(j,n) ) % MOD;
		printf("Case #%d: %d\n",i,res );
	}
	return 0;
}
