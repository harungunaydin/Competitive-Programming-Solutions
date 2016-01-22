#include <iostream>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define all(x) x.begin(),x.end()
#define MAXN 100000
#define MOD 1000000007
using namespace std;
long long A[MAXN+5],B[MAXN+5];
long long DP[MAXN+5][2];
void solve()
{
	int N,i;
	scanf("%d",&N);
	FOR(i,1,N)
		scanf("%lld",A+i);
	FOR(i,1,N-1)
		scanf("%lld",B+i);
	DP[1][0]=A[1];
	DP[1][1]=B[1];
	FOR(i,2,N)
	{
		DP[i][0] = DP[i-1][0] * (A[i] + B[i-1]) + DP[i-1][1] * (A[i]+B[i-1]-1);
		DP[i][1] = (DP[i-1][0]+DP[i-1][1]) * B[i];
		DP[i][0] %= MOD;
		DP[i][1] %= MOD;
	}
	printf("%lld\n",DP[N][0]);
}
int main()
{
	solve();
	return 0;
}
