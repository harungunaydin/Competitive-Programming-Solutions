#include <iostream>
#include <cstdio>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define TFOR(i,a,b) for(i=a; i>=b; i--)
#define MAXN 1500
using namespace std;
int M,N;
int A[MAXN+5][MAXN+5],DP[MAXN+5][MAXN+5];
int T[MAXN+5][MAXN+5][2];
void read()
{
	int a,i,j;
	char c;
	scanf("%d %d",&M,&N);
	FOR(i,1,M)
		FOR(j,1,N)
		{
			scanf(" %c %d",&c,&a);
			A[i][j] = (c == 'A') ? a : -a;
		}
}
void init()
{
	int i,j;
	FOR(i,1,M)
		FOR(j,1,N)
		{
			T[i][j][0] = T[i][j-1][0] + T[i-1][j][0] - T[i-1][j-1][0] + (A[i][j] > 0) * A[i][j];
			T[i][j][1] = T[i][j-1][1] + T[i-1][j][1] - T[i-1][j-1][1] + (A[i][j] < 0) *-A[i][j];
		}
}
int hesapla(int x1,int y1,int x2,int y2,bool k)
{
	return T[x2][y2][k] - T[x2][y1-1][k] - T[x1-1][y2][k] + T[x1-1][y1-1][k];
}
int solve()
{
	int a,b,i,j,t1,t2,t3;
	TFOR(i,M,1)
		TFOR(j,N,1)
		{
			a = hesapla(i,j+1,i,N,1);
			b = hesapla(i+1,j,M,j,0);
			t1 = t2 = t3 = 0;
			if(i+1 <= M) t1 = DP[i+1][j] + a;
			if(j+1 <= N) t2 = DP[i][j+1] + b;
			if(i+1 <= M && j+1 <= N) t3 = DP[i+1][j+1] + a + b;
			DP[i][j] = max(t1,max(t2,t3));
		}
	return DP[1][1];
}
int main()
{
	read();
	init();
	printf("%d\n",solve());
	return 0;
}
