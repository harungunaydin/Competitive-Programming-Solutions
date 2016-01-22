#include <iostream>
#include <cstdio>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define TFOR(i,a,b) for(i=a; i>=b; i--)
#define MIN(a,b) ( ( (a) < (b) ) ? (a) : (b) )
#define R(x) ( (x) * (x)  )
#define INF 200000000
#define MAXN 100001
using namespace std;
int N,c;
int A[MAXN];
int DP[2][102];
void solve()
{
	int i,j,mini,now(1),pre(0),res(INF);
	scanf("%d %d",&N,&c);
	FOR(i,1,N) scanf("%d",A+i);
	FOR(i,0,100) DP[now][i] = (i >= A[1]) ? R(i - A[1]) : INF;
	FOR(i,2,N)
	{
		pre = now;
		now = !now;
		mini = INF;
		FOR(j,0,100)
		{
			mini = MIN( mini , DP[pre][j] - c*j );
			DP[now][j] = (j >= A[i]) ? mini + c*j + R(j-A[i]) : INF;
		}
		mini = INF;
		TFOR(j,100,0)
		{
			mini = MIN( mini , DP[pre][j] + c*j );
			DP[now][j] = (j >= A[i]) ? MIN( DP[now][j] , mini - c*j + R(j-A[i])) : INF;
		}
	}
	FOR(i,0,100)
		res = MIN( res , DP[now][i] );
	printf("%d\n" , res );
}
int main()
{
	solve();
	return 0;
}
