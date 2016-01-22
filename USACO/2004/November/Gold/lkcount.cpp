//SORU 541
//PROGRAM C++
#include <iostream>
#include <fstream>
#include <queue>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define all(x) x.begin(),x.end()
#define INPUT "lkcount.in"
#define OUTPUT "lkcount.out"
#define MAXN 1000
#define EKLE(x,y) { qx.push(x); qy.push(y); A[x][y] = '.'; }
#define BAK(x,y)  { x = qx.front(); y = qy.front(); qx.pop(); qy.pop(); }
#define KONTROL(x,y) (A[x][y] == 'W')
using namespace std;
ifstream in(INPUT);
ofstream out(OUTPUT);
queue <int> qx,qy;
int res;
int yon[8][2] = { {1,0},{1,1},{0,1},{-1,1},{-1,0},{-1,-1},{0,-1},{1,-1} };
char A[MAXN+5][MAXN+5];
void BFS(int x,int y)
{
	res++;
	int i;
	EKLE(x,y);
	while(!qx.empty())
	{
		BAK(x,y);
		FOR2(i,8)
			if(KONTROL(x+yon[i][0],y+yon[i][1]))
				EKLE(x+yon[i][0],y+yon[i][1]);
	}
}
void solve()
{
	int M,N,i,j;
	in >> M >> N;
	FOR(i,1,M)
		FOR(j,1,N)
			in >> A[i][j];
	FOR(i,1,M)
		FOR(j,1,N)
			if(A[i][j] == 'W')
				BFS(i,j);
	out << res << endl;
}
int main()
{
	solve();
	return 0;
}
