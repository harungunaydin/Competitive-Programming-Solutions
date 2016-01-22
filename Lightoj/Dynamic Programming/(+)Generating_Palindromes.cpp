#include <iostream>
#include <cstdio>
#include <cstring>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define TFOR(i,a,b) for(i=a; i>=b; i--)
#define MAX(a,b) ( (a) > (b) ? (a) : (b) )
#define MAXN 101
using namespace std;
typedef pair < int , int > pii;
char A[MAXN];
char DP[2][MAXN];
void solve()
{
	short N,i,j,cur(0),pre(1);
	scanf("%s",A+1);
	N = strlen(A+1);
	FOR(i,1,N) DP[cur][i] = 0;
	FOR(i,1,N)
		FOR(j,1,N)
			if(A[i] == A[N-j+1])
				DP[cur][j] = DP[pre][j-1] + 1;
			else
				DP[cur][j] = MAX( DP[cur][j-1] , DP[pre][j] );

	printf("%hd\n" , N - DP[cur][N] );
}
int main()
{
	short T,i;
	scanf("%hd",&T);
	FOR(i,1,T)
	{
		printf("Case %hd: ",i);
		solve();
	}
	return 0;
}
