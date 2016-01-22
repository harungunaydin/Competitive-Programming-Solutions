#include <algorithm>
#include <cstdio>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define TFOR(i,a,b) for(i=a; i>=b; i--)
#define H(x1,y1,x2,y2) ( T[x2][y2] - T[x2][y1-1] - T[x1-1][y2] + T[x1-1][y1-1] )
#define all(x) x.begin(),x.end()
#define MAXN 450
using namespace std;
int M,N;
int T[MAXN][MAXN];
char A[MAXN][MAXN];
void solve()
{
	int i,j,k,res(0),y1,y2;
	scanf("%d %d",&M,&N);
	FOR(i,1,M)
		FOR(j,1,N)
		{
			scanf(" %c" , A[i] + j );
			T[i][j] = T[i][j-1] + T[i-1][j] - T[i-1][j-1] + ( A[i][j] == '.' );
		}

	FOR(y1,1,N)
		FOR(y2,y1,N)
		{
			k = y2 - y1 + 1;

			FOR(i,1,M)
				if(H(i,y1,i,y2) == k)
				{
					j = i;
					while(i <= M && H(i,y1,i,y2) == k) i++;
					i--;
					res = max( res , (i-j+1) + k );
				}
		}

	printf("%d\n" , res * 2 - 1 );



}
int main()
{
	solve();
	return 0;
}
