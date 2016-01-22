#include <iostream>
#include <cstdio>
#include <cstdlib>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define control(x1,y1,x2,y2) (T[x2][y2] - T[x2][y1-1] - T[x1-1][y2] + T[x1-1][y1-1] == ((x2)-(x1)+1)*2 - 1)
#define MAXN 2000
using namespace std;
int N,res;
int T[MAXN+5][MAXN+5];
char A[MAXN+5][MAXN+5];
void init()
{
	int i,j;
	FOR(i,1,N)
		FOR(j,1,N)
			T[i][j] = T[i][j-1] + T[i-1][j] - T[i-1][j-1] + (A[i][j] == '1');
}
inline void f(int x,int y)
{
	register int i = 1;
	while(A[x+i][y] == '1' && A[x-i][y] == '1' && A[x][y-i] == '1' && A[x][y+i] == '1' && control((x-i),(y-i),(x+i),(y+i)))
	{
		res++;
		i++;
	}	
}
void solve()
{
	register int i,j;
	char S[MAXN+5];
	scanf("%d",&N);
	FOR(i,1,N)
	{
		scanf(" %s",S);
		FOR(j,1,N)
			A[i][j] = S[j-1];
	}
	init();
	FOR(i,2,N-1)
		FOR(j,2,N-1)
			if(A[i][j] == '1')
				f(i,j);
	printf("%d\n",res);
}
int main()
{
	solve();
	return 0;
}
