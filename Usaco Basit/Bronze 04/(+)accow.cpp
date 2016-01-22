//SORU 467
//PROGRAM C++
#include <iostream>
#include <fstream>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define TFOR(i,a,b) for(i=a; i>=b; i--)
#define INPUT "accow.in"
#define OUTPUT "accow.out"
#define all(x) x.begin(),x,end()
#define MAXN 200
using namespace std;
ifstream in(INPUT);
ofstream out(OUTPUT);
int A[MAXN+5][MAXN+5],yon[8][2] = { {0,1},{-1,1},{-1,0},{-1,-1},{0,-1},{1,-1},{1,0},{1,1} };
bool control(int x,int y)
{
	for(int i = 0; i<8; i++)
		if(A[x+yon[i][0]][y+yon[i][1]] < A[x][y])
			return 0;
	return 1;
}
void solve()
{
	int M,N,i,j,s=0;
	in >> M >> N;
	FOR2(i,M)
		FOR2(j,N)
			in >> A[i][j];
	FOR(i,1,M-1)
		FOR(j,1,N-1)
			s+=control(i,j);
	out << s << endl;
}
int main()
{
    solve();
    return 0;
}
