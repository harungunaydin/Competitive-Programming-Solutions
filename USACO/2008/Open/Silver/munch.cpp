//SORU 1052
//PROGRAM C++
#include <iostream>
#include <fstream>
#include <queue>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define all(x) x.begin(),x.end()
#define INPUT "munch.in"
#define OUTPUT "munch.out"
#define MAXN 100
#define EKLE(x,y,s) { qx.push(x); qy.push(y); qs.push(s); if(A[x][y] != 'C') A[x][y] = '*';}
#define BAK(x,y,s) { x = qx.front(); y = qy.front(); s = qs.front(); qx.pop(); qy.pop(); qs.pop(); }
#define KONTROL(x,y) (x>=1 && x<=M && y>=1 && y<=N && A[x][y] != '*')
using namespace std;
ifstream in(INPUT);
ofstream out(OUTPUT);
queue <int> qx,qy,qs;
int M,N;
int yon[4][2] = { {1,0},{0,1},{-1,0},{0,-1} };
char A[MAXN+5][MAXN+5];
int solve()
{
	int i,j,hx,hy,s,x,y;
	in >> M >> N;
	FOR(i,1,M)
		FOR(j,1,N)
		{
			in >> A[i][j];
			if(A[i][j] == 'B') EKLE(i,j,0)
			else if(A[i][j] == 'C') hx = i,hy = j;
		}
	while(!qx.empty())
	{
		BAK(x,y,s);
		if(x == hx && y == hy) return s;
		FOR2(i,4)
			if(KONTROL(x+yon[i][0],y+yon[i][1]))
				EKLE(x+yon[i][0],y+yon[i][1],s+1);
	}
}
int main()
{
	out << solve() << endl;
	return 0;
}
