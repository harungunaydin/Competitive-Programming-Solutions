#include <iostream>
#include <algorithm>
#include <cstdio>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define INF 10000000
#define H(x,y) ((A[x] != B[y]) ? abs(A[x]-B[y]) : INF)
#define MAXN 100000
using namespace std;
long long A[MAXN+5],B[MAXN+5],DP[MAXN+5];
void solve()
{
	long long N,i,mini;
	scanf("%lld",&N);
	FOR(i,1,N)
		scanf("%lld %lld",A+i,B+i);
 	sort(A+1,A+N+1);
	sort(B+1,B+N+1);
	FOR(i,1,N)
	{
		mini = DP[i-1] + H(i,i);
		if(i > 1)
		{
			mini = min( mini , DP[i-2] + H(i-1,i-1) + H(i,i) );
			mini = min( mini , DP[i-2] + H(i-1,i) + H(i,i-1) );
		}
		if(i > 2)
		{
			mini = min( mini , DP[i-3] + H(i-2,i-2) + H(i-1,i-1) + H(i,i));
			mini = min( mini , DP[i-3] + H(i-2,i-1) + H(i-1,i-2) + H(i,i));
			mini = min( mini , DP[i-3] + H(i-1,i) + H(i,i-1) + H(i-2,i-2));
			mini = min( mini , DP[i-3] + H(i-2,i) + H(i,i-2) + H(i-1,i-1));
			mini = min( mini , DP[i-3] + H(i-2,i) + H(i-1,i-2) + H(i,i-1));
			mini = min( mini , DP[i-3] + H(i-2,i-1) + H(i-1,i) + H(i,i-2));
		}
		DP[i] = mini;
	}
	printf("%lld\n",DP[N]);
}
int main()
{
	solve();
	return 0;
}
