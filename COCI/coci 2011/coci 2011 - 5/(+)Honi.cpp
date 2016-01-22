#include <cstdio>
#include <iostream>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define MOD 1000000007ll
#define MAXN 100005
using namespace std;
int N;
long long A[MAXN] , B[MAXN] , DP[MAXN] , DP2[MAXN];
void solve()
{
	int i;
	scanf("%d",&N);
	FOR(i,1,N)
		scanf("%lld" , A+i );
	FOR(i,1,N-1)
		scanf("%lld" , B+i );

	DP[1] = A[1];

	DP2[1] = B[1];

	FOR(i,2,N)
	{
		DP[i] = ( ( DP[i-1] * A[i] ) % MOD + ( DP2[i-1] * A[i] ) % MOD + ( DP[i-1] * B[i-1] ) % MOD + DP2[i-1] * max(0ll,(B[i-1]-1)) ) % MOD;
		DP2[i] = ( ( DP[i-1] * B[i] ) % MOD + ( DP2[i-1] * B[i] ) % MOD ) % MOD;
	}

	printf("%lld\n" , DP[N]);

}
int main()
{
	solve();
	return 0;
}
