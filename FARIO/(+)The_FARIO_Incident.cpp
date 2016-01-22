#include <iostream>
#include <cstdio>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define MAXN 1000005
#define MOD 1000003
using namespace std;
typedef pair < int , int > pii;
string A[15] = { "0","24","135","26","157","2468","359","48","579","68" };
int D,N;
int DP[2][15];
void solve()
{
	int cur(0),i,j,k,pre(1),res(0);
	scanf("%d %d",&N,&D);
	DP[0][D] = 1;
	FOR2(i,N-1)
	{
		pre = cur;
		cur = !cur;
		FOR(j,1,9)
		{
			DP[cur][j] = 0;
			FOR2(k,A[j].size())
				DP[cur][j] = ( DP[cur][j] + DP[pre][A[j][k] - '0'] ) % MOD;
		}
	}
	FOR(i,1,9) res += DP[cur][i];
	printf("%d\n" , res % MOD );
}
int main()
{
	solve();
	return 0;
}
