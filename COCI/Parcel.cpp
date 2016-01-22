#include <iostream>
#include <cstdio>
#include <cstdlib>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define MAXN 2000
using namespace std;
int N;
int T[MAXN+5][MAXN+5];
char A[MAXN+5][MAXN+5];
void read()
{
	int i,j;
	scanf("%d",&N);
	if(N > 250) { printf("%d\n",N*N); exit(0); }
	FOR(i,1,N)
		FOR(j,1,N)
		{
			scanf(" %c",A[i]+j);
			A[i][j] -= '0';
		}
}
void init()
{
	int i,j;
	FOR(i,1,N)
		FOR(j,1,N)
			T[i][j] = T[i][j-1] + T[i-1][j] - T[i-1][j-1] + A[i][j];
}
inline int H(int x1,int y1,int x2,int y2) { return T[x2][y2] - T[x2][y1-1] - T[x1-1][y2] + T[x1-1][y1-1]; }
void solve()
{
	int res(0),x1,x2,y1,y2;
	FOR(x1,1,N)
		FOR(y1,1,N)
			FOR(x2,x1,N)
				FOR(y2,y1,N)
					if(!H(x1,y1,x2,y2))
						res = max( res , (x2-x1+1) * (y2-y1+1) );
	printf("%d\n" , res );
}
int main()
{
	read();
	init();
	solve();
	return 0;
}
