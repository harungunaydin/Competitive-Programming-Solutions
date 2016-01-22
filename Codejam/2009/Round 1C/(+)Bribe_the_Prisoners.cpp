#include <iostream>
#include <cstdio>
#include <cstring>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define TFOR(i,a,b) for(i=a; i>=b; i--)
#define INF 1000000
#define MAXN 105
using namespace std;
inline int Min( int a , int b ) { return a < b ? a : b; }
int M,N;
int A[MAXN];
int DP[MAXN][MAXN];
int MCP(int bas,int son)
{
	int &ret = DP[bas][son];
	if(ret != -1) return ret;
	if(bas > son) return ret = 0;

	ret = INF;

	int i;

	FOR(i,bas,son)
		ret = Min( ret , MCP(bas,i-1) + MCP(i+1,son) );

	return ret = ret + ( A[son+1] - 1 - ( A[bas-1] + 1 ) + 1 - 1 );
}
void solve()
{
	memset( DP , -1 , sizeof DP );
	int i;
	scanf("%d %d",&M,&N);
	FOR(i,1,N) scanf("%d",A+i);
	A[N+1] = M + 1;
	printf("%d\n" , MCP(1,N) );
}
int main()
{
	int T,i;
	scanf("%d",&T);
	FOR(i,1,T)
	{
		printf("Case #%d: ",i);
		solve();
	}
	return 0;
}
