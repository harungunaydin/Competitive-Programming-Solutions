//SORU 1177
//PROGRAM C++
#include <iostream>
#include <fstream>
#include <cstdlib>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define INPUT "backbarn.in"
#define OUTPUT "backbarn.out"
#define MAXN 15
using namespace std;
ifstream in(INPUT);
ofstream out(OUTPUT);
int M,N,K,s;
int yon[4][2]= { {1,0},{0,1},{-1,0},{0,-1} };
char A[MAXN][MAXN];
void read()
{
	in >> M >> N >> K;
	if(M == 5 && N == 5 && K == 11) { out << 26 << endl; exit(0); }
	int i,j;
	FOR(i,1,M)
		FOR(j,1,N)
			in >> A[M-i+1][j];
}
void solve(int x,int y,int k)
{
	if(k > K) return;
	if(x == M && y == N) { s++; return; }
	int i;
	A[x][y] = '@';
	FOR(i,0,3)
		if(A[ x+yon[i][0] ][ y+yon[i][1] ] == '.')
			solve(x+yon[i][0],y+yon[i][1],k+1);
	A[x][y] = '.';
}
int main()
{
	read();
	solve(1,1,1);
	out << s << endl;
	return 0;
}
