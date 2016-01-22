#include <cstdio>
#include <cstring>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define INF 5000
#define MAXN 102
using namespace std;
short Max( short a , short b ) { return a > b ? a : b; }
short K,M,N;
short A[MAXN][MAXN];
short DP[201][MAXN][MAXN];
short dp(int x,int x1,int x2)
{
	short &ret = DP[x][x1][x2];
	if(ret) return ret;

	short y1 = x - x1;
	short y2 = x - x2;
	
	if(x1 > M || y1 > N || x2 > M || y2 > N) return ret = -INF;
	if(x == K) return ret = A[M][N];
	if(x1 == x2 && y1 == y2) return ret = -INF;

	ret = dp(x+1,x1+1,x2);

	ret = Max( ret , dp(x+1,x1,x2) );
	ret = Max( ret , dp(x+1,x1,x2+1) );
	ret = Max( ret , dp(x+1,x1+1,x2+1) );

	return ret += A[x1][y1] + A[x2][y2];
}

void solve()
{
	memset( DP , 0 , sizeof DP );
	short i,j;
	scanf("%hd %hd",&M,&N);
	K = M + N;
	FOR(i,1,M)
		FOR(j,1,N)
			scanf("%hd",A[i]+j);

	printf("%hd\n" , dp(3,1,2) + A[1][1] );
}
int main()
{
	short T,i;
	scanf("%hd",&T);
	FOR(i,1,T)
	{
		printf("Case %hd: ",i);
		solve();
	}
	return 0;
}
