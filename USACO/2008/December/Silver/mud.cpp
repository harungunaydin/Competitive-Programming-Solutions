//SORU 1013
//PROGRAM C++
#include <iostream>
#include <fstream>
#include <queue>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define all(x) x.begin(),x.end()
#define INPUT "mud.in"
#define OUTPUT "mud.out"
#define MAXN 1000
#define EKLE(x,y,s) { qx.push(x); qy.push(y); qs.push(s); A[x][y] = true; }
#define BAK(x,y,s)  { x = qx.front(); y = qy.front(); s = qs.front(); qx.pop(); qy.pop(); qs.pop(); }
#define KONTROL(x,y) (x>=0 && x<=1000 && y>=0 && y<=1000 && !A[x][y])
using namespace std;
ifstream in(INPUT);
ofstream out(OUTPUT);
queue <int> qx,qy,qs;
int yon[4][2] = { {1,0},{0,1},{-1,0},{0,-1} };
bool A[MAXN+5][MAXN+5];
int solve()
{
	int M,a,b,i,s,x,y;
	in >> x >> y >> M;
	FOR(i,1,M)
	{
		in >> a >> b;
		A[a+500][b+500] = true;
	}
	EKLE(x+500,y+500,0);
	while(!qx.empty())
	{
		BAK(x,y,s);
		if(x == 500 && y == 500) return s;
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
