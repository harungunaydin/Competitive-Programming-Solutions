#include <algorithm>
#include <cstdio>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define TFOR(i,a,b) for(i=a; i>=b; i--)
#define A(x,y) A[x][y]
#define all(x) x.begin(),x.end()
#define MAXN 35
using namespace std;
int N;
char A[MAXN][MAXN];
char solve()
{
	int i,j;
	char c;
	scanf("%d",&N);
	FOR(i,2,N+1)
		FOR(j,2,N+1)
			scanf(" %c" , A[i] + j );

	FOR(i,2,N+1)
		FOR(j,2,N+1)
			if(A[i][j] != '.')
			{
				c = A[i][j];
				if( A(i+1,j) == c && A(i+2,j) == c ) return c;
				if( A(i-1,j) == c && A(i-2,j) == c ) return c;
				if( A(i,j+1) == c && A(i,j+2) == c ) return c;
				if( A(i,j-1) == c && A(i,j-2) == c ) return c;
				if( A(i+1,j+1) == c && A(i+2,j+2) == c ) return c;
				if( A(i+1,j-1) == c && A(i+2,j-2) == c ) return c;
				if( A(i-1,j+1) == c && A(i-2,j+2) == c ) return c;
				if( A(i-1,j-1) == c && A(i-2,j-2) == c ) return c;
			}
	return 0;
}
int main()
{
	char res = solve();
	if(res) printf("%c\n" , res );
	else printf("ongoing\n");
	return 0;
}
