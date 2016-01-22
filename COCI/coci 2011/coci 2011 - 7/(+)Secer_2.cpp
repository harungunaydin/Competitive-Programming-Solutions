#include <iostream>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define MAXN 5000
using namespace std;
int DP[MAXN+10];
int solve()
{
	int N,i;
	scanf("%d",&N);
	DP[0] = 1;
	FOR(i,0,N)
		if(DP[i] && (DP[i] + 1 < DP[i+3] || !DP[i+3]))
			DP[i+3] = DP[i] + 1;
	FOR(i,0,N)
		if(DP[i] && (DP[i] + 1 < DP[i+5] || !DP[i+5]))
			DP[i+5] = DP[i] + 1;
	return (DP[N]) ? DP[N]-1 : -1;
}
int main()
{
	printf("%d\n",solve());
	return 0;
}
