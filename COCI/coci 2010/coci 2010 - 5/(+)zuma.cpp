#include <algorithm>
#include <cstdio>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define TFOR(i,a,b) for(i=a; i>=b; i--)
#define all(x) x.begin(),x.end()
#define MAXN 105
using namespace std;
int K,N;
int A[MAXN];
int DP[MAXN][MAXN][6];
int dp(int x,int y,int k)
{
	int &ret = DP[x][y][k];
	if(ret) return ret;
	if(x > y) return 0;

	ret = 20000000;

	if(k == K - 1) ret = min( ret , dp(x+1,y,0) );

	int i;
	FOR(i,x+1,y)
		if( A[i] == A[x] )
			ret = min( ret , dp(x+1,i-1,0) + dp(i,y,min(K-1,k+1) ) );

	if(k + 1 <= K - 1) ret = min( ret , dp(x,y,k+1) + 1 );

	return ret;

}
void solve()
{
	int i;
	scanf("%d %d",&N,&K);

	FOR(i,1,N)
		scanf("%d" , A+i );

	printf("%d\n" , dp(1,N,0) );

}
int main()
{
	solve();
	return 0;
}
