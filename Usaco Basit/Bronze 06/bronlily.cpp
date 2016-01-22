//SORU 531
//PROGRAM C++
#include <iostream>
#include <fstream>
#include <queue>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define all(x) x.begin(),x.end()
#define INPUT "bronlily.in"
#define OUTPUT "bronlily.out"
#define MAXN 30
#define EKLE(x,y,s) { qx.push(x); qy.push(y); qs.push(s); if(A[x][y] != 4) A[x][y] = 2; }
#define BAK(x,y,s) { x = qx.front(); y = qy.front(); s = qs.front(); qx.pop(); qy.pop(); qs.pop(); }
#define KONTROL(x,y) (x>=1 && x<=M && y>=1 && y<=N && (A[x][y] == 1 || A[x][y] == 4))
using namespace std;
ifstream in(INPUT);
ofstream out(OUTPUT);
queue <int> qx,qy,qs;
int M,N;
int A[MAXN+5][MAXN+5];
int solve()
{
	int m1,m2,i,j,s,x,y;
	in >> M >> N >> m1 >> m2;
	int yon[8][2] = { {m1,m2},{m2,m1},{m1,-m2},{m2,-m1},{-m1,-m2},{-m2,-m1},{-m1,m2},{-m2,m1} };
	FOR(i,1,M)
		FOR(j,1,N)
		{
			in >> A[i][j];
			if(A[i][j] == 3)
				EKLE(i,j,0);
		}
	while(!qx.empty())
	{
		BAK(x,y,s);
		if(A[x][y] == 4) return s;
		FOR2(i,8)
			if(KONTROL(x+yon[i][0],y+yon[i][1]))
				EKLE(x+yon[i][0],y+yon[i][1],s+1);
	}
	return -1;
}
int main()
{
	out << solve() << endl;
	return 0;
}
