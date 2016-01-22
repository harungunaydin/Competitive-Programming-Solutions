#include <cstdio>
#include <cstring>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define INF 200000000
#define MAXN 22
using namespace std;
inline int Min( int a , int b ) { return a < b ? a : b; }
int N;
int B[MAXN],G[MAXN],R[MAXN];
int DP[MAXN][4];
int dp(int x,int pre)
{
	int &ret = DP[x][pre];
	if(ret) return ret;
	
	if(x == N + 1) return ret = 0;

	ret = INF;

	if(pre != 0) ret = Min( ret , dp(x+1,0) + R[x] );
	if(pre != 1) ret = Min( ret , dp(x+1,1) + G[x] );
	if(pre != 2) ret = Min( ret , dp(x+1,2) + B[x] );
	
	return ret;
}
void solve()
{
	memset( DP , 0 , sizeof DP );
	int i;
	scanf("%d",&N);
	FOR(i,1,N)
		scanf("%d %d %d",R+i,G+i,B+i);

	printf("%d\n" , dp(1,3) );
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
