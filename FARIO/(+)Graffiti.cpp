#include <iostream>
#include <cstdio>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define TFOR(i,a,b) for(i=a; i>=b; i--)
#define MAXN 500000
using namespace std;
inline long long Max( long long a , long long b ) { return a > b ? a : b; }
int N;
long long DP[MAXN];
int A[MAXN][4];
long long dp(int x)
{
	long long &ret = DP[x];
	if(ret) return ret;
	if(x >= N) return 0;
	ret = dp(x+1);
	return ret = Max( ret , dp(x+2) + A[x][1] + A[x+1][1] + Max( A[x][0] + A[x+1][0] , A[x][2] + A[x+1][2] ) );
}
void solve()
{
	int i,j;
	scanf("%d",&N);
	FOR(i,1,N)
		scanf("%d %d %d",A[i],A[i]+1,A[i]+2);
	TFOR(i,N,1)
		dp(i);
	printf("%lld\n" , dp(1) );
}
int main()
{
	solve();
	return 0;
}
