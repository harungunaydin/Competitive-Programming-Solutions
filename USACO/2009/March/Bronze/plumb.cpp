//SORU 1232
//PROGRAM C++
#include <iostream>
#include <fstream>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define INPUT "plumb.in"
#define OUTPUT "plumb.out"
#define MAXN 55
using namespace std;
ifstream in(INPUT);
ofstream out(OUTPUT);
int M,N;
int A[MAXN][MAXN],yon[8][2]={ {1,0},{1,1},{0,1},{-1,1},{-1,0},{-1,-1},{0,-1},{1,-1} };
int kontrol(int x,int y)
{
	int i,maxi=0;
	FOR(i,0,7)
		if(A[ x+yon[i][0] ][ y+yon[i][1] ] == A[x][y])
			maxi=max(maxi,A[x][y]);
	return maxi;
}
void solve()
{
	int i,j,maxi=0;
	in >> M >> N;
	FOR(i,1,M)
		FOR(j,1,N)
			in >> A[i][j];
	FOR(i,1,M)
		FOR(j,1,N)
			maxi=max(maxi,kontrol(i,j));
	out << maxi << endl;
}
int main()
{
	solve();
	return 0;
}
