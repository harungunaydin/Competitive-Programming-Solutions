#include <iostream>
#include <cstdio>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define all(x) x.begin(),x.end()
#define MAXN 250
using namespace std;
int N,R;
int A[MAXN+5][MAXN+5],D[MAXN+5][MAXN+5];
void init()
{
	int i,j;
	FOR(i,1,N)
		FOR(j,1,N)
			D[i][j] = D[i][j-1] + D[i-1][j] - D[i-1][j-1] + A[i][j];
}
inline int hesapla(int x,int y)
{
	int x1,y1,x2,y2;
	x1 = max(x - R , 1); x2 = min(x + R , N);
	y1 = max(y - R , 1); y2 = min(y + R , N);
	return D[x2][y2] - D[x2][y1-1] - D[x1-1][y2] + D[x1-1][y1-1];
}
void solve()
{
	int i,j;
	scanf("%d %d",&N,&R);
	FOR(i,1,N)
		FOR(j,1,N)
			scanf("%d",A[i]+j);
	init();
	FOR(i,1,N)
		FOR(j,1,N)
			printf("%d%c",hesapla(i,j),(j != N) ? ' ' : '\n');
}
int main()
{
	solve();
	return 0;
}
