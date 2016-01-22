#include <cstdio>
#include <cstring>
#include <iostream>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define TFOR(i,a,b) for(i=a; i>=b; i--)
#define INF 200000000
#define f first
#define s second
#define MAXN 605
using namespace std;
typedef pair < int , int > pii;
inline int Max( int a , int b ) { return a > b ? a : b; }
pii P[205];
int M,N,K;
int DP[MAXN][MAXN];
int dp(int x,int y)
{
	int &ret = DP[x][y];
	if(ret != -1) return ret;
	int i,t1,t2;
	ret = 0;
	FOR(i,1,K)
		if(P[i].f <= x && P[i].s <= y)
		{
			t1 = dp(x,y-P[i].s) + dp(x-P[i].f,P[i].s);
			t2 = dp(x-P[i].f,y) + dp(P[i].f,y-P[i].s);
			t1 = Max( t1 , t2 );
			ret = Max( ret , t1 + P[i].f * P[i].s );
		}
	return ret;
}
void solve()
{
	memset( DP , -1 , sizeof DP );
	scanf("%d %d",&N,&M);
	scanf("%d",&K);
	int i;
	FOR(i,1,K)
		scanf("%d %d",&P[i].s,&P[i].f);


	printf("%d\n" , M * N - dp(M,N) );


}
int main()
{
	solve();
	return 0;
}
