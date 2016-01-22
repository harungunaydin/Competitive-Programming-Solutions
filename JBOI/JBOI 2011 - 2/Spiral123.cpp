#include <iostream>
#include <fstream>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define MAXN 200
using namespace std;
int N;
int A[MAXN+5][MAXN+5];
int yon[4][2] = { {0,1},{1,0},{0,-1},{-1,0} };
bool sat[MAXN+5][4],sut[MAXN+5][4];
void print()
{
	int i,j;
	FOR(i,1,N)
		if(!(sat[i][1] && sat[i][2] && sat[i][3] && sut[i][1] && sut[i][2] && sut[i][3]))
			return;
	FOR(i,1,N)
		FOR(j,1,N)
			printf("%d%c",A[i][j],(j != N) ? ' ' : '\n');
	exit(0);
}
inline void rec(int x,int y,int k,int t,int s)
{
	if(s == N * N) { print(); return; }
	int q = (k+1)%4,xx = x + yon[k][0],yy = y + yon[k][1],tt = (t == 3) ? 1 : t+1;
	if(sat[x][t] || sut[y][t])
	{
		A[x][y] = 0;
		(A[xx][yy] == -1) ? rec(xx,yy,k,t,s+1) : rec(x+yon[q][0],y+yon[q][1],q,t,s+1);
		A[x][y] = -1;
		return;
	}
	A[x][y] = t;
	sat[x][t] = sut[y][t] = true;
	(A[xx][yy] == -1) ? rec(xx,yy,k,tt,s+1) : rec(x+yon[q][0],y+yon[q][1],q,tt,s+1);
	sat[x][t] = sut[y][t] = A[x][y] = false;
	(A[xx][yy] == -1) ? rec(xx,yy,k,t,s+1) : rec(x+yon[q][0],y+yon[q][1],q,t,s+1);
	A[x][y] = -1;
}
int main()
{
	scanf("%d",&N);
	int i,j;
	FOR(i,1,N)
		FOR(j,1,N)
			A[i][j] = -1;
	rec(1,1,0,1,0);	
	return 0;
}
