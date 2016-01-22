//SORU 372
//PROGRAM C++
#include <iostream>
#include <fstream>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define TFOR(i,a,b) for(i=a; i>=b; i--)
#define INPUT "numtri.in"
#define OUTPUT "numtri.out"
#define MAXN 1000
using namespace std;
ifstream in(INPUT);
ofstream out(OUTPUT);
int N;
int A[MAXN+5][MAXN+5];
void solve()
{
	int i,j;
	in >> N;
	FOR(i,1,N)
		FOR(j,1,i)
			in >> A[i][j];
	TFOR(i,N,1)
		FOR(j,1,i)
			A[i-1][j]+=max(A[i][j],A[i][j+1]);
	out << A[1][1] << endl;
}
int main()
{
	solve();
	return 0;
}
