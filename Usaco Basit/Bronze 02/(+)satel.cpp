//SORU 449
//PROGRAM C++
#include <iostream>
#include <fstream>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define all(x) x.begin(),x.end()
#define INPUT "satel.in"
#define OUTPUT "satel.out"
#define MAXN 75
#define KONTROL(x,y) (x>=1 && x<=M && y>=1 && y<=N && A[x][y] == '#' && !visited[x][y])
using namespace std;
ifstream in(INPUT);
ofstream out(OUTPUT);
int M,N,a,b,c,d,res1,res2;
int yon[4][2] = { {1,0},{0,1},{-1,0},{0,-1} };
char A[MAXN+5][MAXN+5];
bool flag;
bool visited[MAXN+5][MAXN+5];
void control(int x1,int x2,int y1,int y2)
{
	int i,j;
	FOR(i,x1,x2)
		FOR(j,y1,y2)
			if(A[i][j] != '#')
				return;
	FOR(i,x1,x2)
		FOR(j,y1,y2)
			A[i][j] = '.';
	res1++;
}
void dfs(int x,int y)
{
	if(x<a || x>c || y<b || y>d) flag = true;
	if(flag) return;
	visited[x][y] = true;
	int i;
	FOR2(i,4)
		if(KONTROL(x+yon[i][0],y+yon[i][1]) && !flag)
			dfs(x+yon[i][0],y+yon[i][1]);
}
void dfs2(int x,int y)
{
	A[x][y] = '.';
	int i;
	FOR2(i,4)
		if(KONTROL(x+yon[i][0],y+yon[i][1]))
			dfs2(x+yon[i][0],y+yon[i][1]);
}
void solve()
{
	int i,j,k;
	in >> M >> N;
	FOR(i,1,M)
		FOR(j,1,N)
			in >> A[i][j];
	FOR(i,1,M)
		FOR(j,1,N)
			if(A[i][j] == '#')
			{
				c = i+1;
				while(A[c][j] == '#' && c<=M) c++;
				d = j+1;
				while(A[i][d] == '#' && d<=N) d++;
				a = i; b = j; c--; d--;
				flag = false;
				dfs(i,j);
				if(!flag)
					control(a,c,b,d);
				FOR(a,1,N)
					FOR(b,1,N)
						visited[a][b] = false;
			}
	FOR(i,1,M)
		FOR(j,1,N)
			if(A[i][j] == '#')
			{
				res2++;
				dfs2(i,j);
			}
	out << res1 << " " << res2 << endl;
}
int main()
{
	solve();
	return 0;
}
