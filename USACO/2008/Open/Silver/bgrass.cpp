//SORU 1049
//PROGRAM C++
#include <iostream>
#include <fstream>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define all(x) x.begin(),x.end()
#define INPUT "bgrass.in"
#define OUTPUT "bgrass.out"
#define MAXN 100
using namespace std;
ifstream in(INPUT);
ofstream out(OUTPUT);
char A[MAXN+5][MAXN+5];
void solve()
{
	int M,N,i,j,res(0);
	in >> M >> N;
	FOR(i,1,M)
		FOR(j,1,N)
			in >> A[i][j];
	FOR(i,1,M)
		FOR(j,1,N)
			if(A[i][j] == '#')
			{
				res++;
				A[i][j+1] = A[i+1][j] = '.';
			}
	out << res << endl;
}
int main()
{
	solve();
	return 0;
}
