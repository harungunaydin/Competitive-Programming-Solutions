#include <algorithm>
#include <cstdio>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define TFOR(i,a,b) for(i=a; i>=b; i--)
#define all(x) x.begin(),x.end()
#define MAXN 55
using namespace std;
int M,N;
char A[MAXN][MAXN] , B[MAXN*2][MAXN*2];
void solve()
{
	int i,j;
	scanf("%d %d",&M,&N);
	FOR(i,1,M)
		FOR(j,1,N)
		{
			scanf(" %c" , A[i] + j );
			B[i][j] = A[i][j];
		}

	FOR(i,1,M)
		FOR(j,N+1,2*N)
			B[i][j] = B[i][2*N-j+1];

	FOR(i,M+1,2*M)
		FOR(j,1,2*N)
			B[i][j] = B[2*M-i+1][j];

	int a,b;
	scanf("%d %d",&a,&b);

	B[a][b] = ( B[a][b] == '#' ) ? '.' : '#';

	for(i = 1; i <= 2*M; i++,printf("\n"))
		FOR(j,1,2*N)
			printf("%c" , B[i][j] );


}
int main()
{
	solve();
	return 0;
}
