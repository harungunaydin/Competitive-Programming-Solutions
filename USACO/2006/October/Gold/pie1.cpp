//SORU 545
//PROGRAM C++
#include <iostream>
#include <fstream>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define TFOR(i,a,b) for(i=a; i>=b; i--)
#define INPUT "pie1.in"
#define OUTPUT "pie1.out"
#define MAXN 100
using namespace std;
ifstream in(INPUT);
ofstream out(OUTPUT);
int M,N;
int A[MAXN+5][MAXN+5],DP[MAXN+5][MAXN+5];
void solve()
{
	int i,j;
	in >> M >> N;
	FOR(i,1,M)
		FOR(j,1,N)
			in >> A[i][j];
		FOR(j,1,N)
			for(i=1; i<=j && i<=M; i++)
				DP[i][j] = max(DP[i-1][j-1],max(DP[i][j-1],DP[i+1][j-1])) + A[i][j];
	out << DP[M][N] << endl;
}
int main()
{
	solve();
	return 0;
}
