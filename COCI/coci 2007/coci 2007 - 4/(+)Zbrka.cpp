#include <cstdio>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define MAXN 1005
#define MAXC 10005
#define MOD 1000000007
using namespace std;
int C,N;
long long DP[MAXC] , T[MAXC];
int main()
{
	int N,i,j,k;
	scanf("%d %d",&N,&C);

	FOR(i,0,C) T[i] = 1;
	
	FOR(i,2,N)
	{
		FOR(j,0,C)
		{
			DP[j] = T[j];
			if(j >= i)
				DP[j] = ( DP[j] - T[j-i] + MOD ) % MOD;
		}
		T[0] = DP[0];
		FOR(j,1,C) T[j] = ( T[j-1] + DP[j] ) % MOD;

	}

	printf("%lld\n" , DP[C] );

	return 0;
}
