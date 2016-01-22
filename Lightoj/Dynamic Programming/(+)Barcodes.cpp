#include <cstdio>
#include <cstring>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define MAXN 51
using namespace std;
int K,M,N;
long long DP[MAXN][MAXN][MAXN];
int main()
{
	long long s(0);
	int T,i,j,k,t;
	scanf("%d",&T);
	FOR(M,1,50)
	{
		DP[0][0][M] = 1; 
		FOR(N,1,50)
		{
			t = (M < N) ? M : N;
			FOR(K,1,50)
			{
				s = 0;
				FOR(i,1,t)
					s += DP[N-i][K-1][M];
				DP[N][K][M] = s;		
			}
		}
	}
	FOR(i,1,T)
	{
		scanf("%d %d %d",&N,&K,&M);
		printf("Case %d: %lld\n" , i , DP[N][K][M] );
	}
	return 0;
}
