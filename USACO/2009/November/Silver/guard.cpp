//SORU 1164
//PROGRAM C++
#include <iostream>
#include <fstream>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define all(x) x.begin(),x.end()
#define INPUT "guard.in"
#define OUTPUT "guard.out"
#define MAXN 100
using namespace std;
ifstream in(INPUT);
ofstream out(OUTPUT);
int vis;
int yon[8][2] = { {1,0},{1,1},{0,1},{-1,1},{-1,0},{-1,-1},{0,-1},{1,-1} };
int A[MAXN+5][MAXN+5],visited[MAXN+5][MAXN+5];
bool flag;
bool visited2[MAXN+5][MAXN+5];
void rec(int x,int y,int k)
{
	if(visited[x][y] == vis) return;
	visited[x][y] = vis;
	if(A[x][y] > k) { flag = true; return; }
	if(flag) return;
	if(A[x][y] == k)
		for(int i = 0; i < 8; i++)
			rec(x+yon[i][0],y+yon[i][1],k);
}
void rec2(int x,int y,int k)
{
	if(visited2[x][y]) return;
	visited2[x][y] = true;
	int i;
	FOR2(i,8)
		if(A[x+yon[i][0]][y+yon[i][1]] == k)
			rec2(x+yon[i][0],y+yon[i][1],k);
}
void solve()
{
	int M,N,i,j,res=0;
	in >> M >> N;
	FOR(i,1,M)
		FOR(j,1,N)
			in >> A[i][j];
	FOR(i,1,M)
		FOR(j,1,N)
			if(A[i][j] && !visited2[i][j])
			{
				flag = false;
				vis++;
				rec(i,j,A[i][j]);
				if(!flag)
					rec2(i,j,A[i][j]);
				res += (!flag);
			}
	out << res << endl;
}
int main()
{
	solve();
	return 0;
}
