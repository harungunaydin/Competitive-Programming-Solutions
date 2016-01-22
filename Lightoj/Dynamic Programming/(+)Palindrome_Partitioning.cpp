#include <iostream>
#include <cstdio>
#include <cstring>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define TFOR(i,a,b) for(i=a; i>=b; i--)
#define OO 10000000
#define MAXN 1001
using namespace std;
typedef pair < int , int > pii;
char A[MAXN];
int DP[MAXN];
bool IS_PAL[MAXN][MAXN];
void solve()
{
	int N,i,j,res;
	scanf("%s",A+1);

	N = strlen(A+1);

	TFOR(i,N,1)
		FOR(j,1,N)
			if(i == j)
				IS_PAL[i][j] = true;
			else if(i + 1 == j)
				IS_PAL[i][j] = (A[i] == A[j]);
			else
				IS_PAL[i][j] = (IS_PAL[i+1][j-1] && A[i] == A[j]);

	FOR(i,1,N)
	{
		res = OO;
		FOR(j,1,i)
			if(IS_PAL[j][i] && DP[j-1] < res)
				res = DP[j-1];
		DP[i] = res + 1;
	}
	printf("%d\n" , DP[N] );
}
int main()
{
	int T,i;
	scanf("%d",&T);
	FOR(i,1,T)
	{
		printf("Case %d: ",i);
		solve();
	}
	return 0;
}
