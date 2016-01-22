//SORU 1176
//PROGRAM C++
#include <iostream>
#include <fstream>
#include <queue>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define all(x) x.begin(),x.end()
#define INPUT "lphone.in"
#define OUTPUT "lphone.out"
#define MAXN 100
#define EKLE(x,y,s) { qx.push(x); qy.push(y); qs.push(s); }
#define BAK(x,y,s) { x = qx.front(); y = qy.front(); s = qs.front(); qx.pop(); qy.pop(); qs.pop(); }
#define KONTROL(x,y) (x>=1 && x<=M && y>=1 && y<=N && A[x][y] != '*')
#define INF 1000000000
using namespace std;
ifstream in(INPUT);
ofstream out(OUTPUT);
queue <int> qx,qy,qs;
int M,N,rx,ry;
int  B[MAXN+5][MAXN+5];
char A[MAXN+5][MAXN+5];
bool visited[MAXN+5][MAXN+5][MAXN+5];
void read()
{
	int i,j;
	in >> N >> M;
    FOR(i,1,M)
    	FOR(j,1,N)
    	{
    		in >> A[i][j];
    		if(A[i][j] == 'C')
				EKLE(i,j,1);
		}
	BAK(rx,ry,i);
}
void solve()
{
	int i,j,s,x,y;
	FOR(i,1,M)
		FOR(j,1,N)
			B[i][j] = INF;
	while(!qx.empty())
	{
		BAK(x,y,s);
		if(visited[x][y][s]) continue;
		visited[x][y][s] = true;
		if(s < B[x][y])
			B[x][y] = s;
		i = y+1;
		while(KONTROL(x,i))
		{
			if(s+1 < B[x][i])
				EKLE(x,i,s+1);
			i++;
		}
		i = y-1;
		while(KONTROL(x,i))
		{
			if(s+1 < B[x][i])
				EKLE(x,i,s+1);
			i--;
		}
		i = x-1;
		while(KONTROL(i,y))
		{
			if(s+1 < B[i][y])
				EKLE(i,y,s+1);
			i--;
		}
		i = x+1;
		while(KONTROL(i,y))
		{
			if(s+1 < B[i][y])
				EKLE(i,y,s+1);
			i++;
		}
	}
	out << B[rx][ry] - 2 << endl;
}
int main()
{
    read();
	solve();
	return 0;
}
