#include <iostream>
#define FOR(i,a,b) for(i=a; i<=b; i++)
using namespace std;
int N;
long long A[1000005],B[1000005];
long long  DP[1000005][2];
void solve()
{
	int i;
	scanf("%d",&N);
	FOR(i,1,N) 
		scanf("%d",&A[i]);
	FOR(i,1,N-1)
		scanf("%d",&B[i]);
	DP[1][0]=A[1];
	DP[1][1]=B[1];
	FOR(i,2,N)
	{
		DP[i][0]=( A[i] + B[i-1] ) * DP[i-1][0] + ( A[i] + B[i-1] - 1) * DP[i-1][1];
		DP[i][1]=B[i] * ( DP[i-1][0] + DP[i-1][1] );
		DP[i][0]%=1000000007;
		DP[i][1]%=1000000007;
	}
	printf("%d\n",DP[N][0]);
}
int main()
{
	solve();
	return 0;
}
