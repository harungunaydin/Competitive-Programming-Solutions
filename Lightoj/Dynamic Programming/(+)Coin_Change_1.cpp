#include <iostream>
#include <cstdio>
#include <cstring>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define MAXN 1005
#define MOD 100000007
using namespace std;
typedef pair < int , int > pii;
int DP[55][MAXN];
int K,N;
int A[MAXN] , B[MAXN];
int dp(int x,int k)
{
	int &ret = DP[x][k];
	if(ret != -1) return ret;
	if(x == N + 1) return ret = !k;
	ret = 0;
	int i;
	FOR(i,0,B[x])
		if(k >= i * A[x])
			ret = ( ret + dp(x+1,k - i * A[x]) ) % MOD;
	return ret;
}
void solve()
{
	memset( DP , -1 , sizeof DP );
	
	scanf("%d %d",&N,&K);

	int i;

	FOR(i,1,N) scanf("%d",A+i);
	FOR(i,1,N) scanf("%d",B+i);

	printf("%d\n" , dp(1,K) );
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
