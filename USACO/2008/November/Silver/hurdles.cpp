//SORU 928
//PROGRAM C++
#include <iostream>
#include <fstream>
#include <climits>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define all(x) x.begin(),x.end()
#define INPUT "hurdles.in"
#define OUTPUT "hurdles.out"
#define MAXN 300
using namespace std;
ifstream in(INPUT);
ofstream out(OUTPUT);
int A[MAXN+5][MAXN+5];
int M,N,T;
void solve()
{
	int a,b,c,i,j,k;
	in >> N >> M >> T;
	FOR(i,1,N)
		FOR(j,1,N)
			A[i][j] = INT_MAX;
	FOR(i,1,M)
	{
		in >> a >> b >> c;
		A[a][b] = min(A[a][b],c);
	}
	FOR(k,1,N)
		FOR(i,1,N)
			if(A[i][k] != INT_MAX)
				FOR(j,1,N)
					A[i][j] = min( max(A[i][k],A[k][j]),A[i][j] );
	FOR(i,1,T)
	{
		in >> a >> b;
		out << ((A[a][b] == INT_MAX) ? -1 : A[a][b]) << endl;
	}
}
int main()
{
	solve();
	return 0;
}
