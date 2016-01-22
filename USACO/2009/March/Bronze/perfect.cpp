//SORU 1233
//PROGRAM C++
#include <iostream>
#include <fstream>
#include <algorithm>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define INPUT "perfect.in"
#define OUTPUT "perfect.out"
#define MAXN 105
using namespace std;
ifstream in(INPUT);
ofstream out(OUTPUT);
int N;
int A[MAXN][MAXN],B[MAXN];
void solve()
{
	int i,j;
	in >> N;
	FOR(i,1,N)
	{
		FOR(j,1,N)
			in >> A[i][j];
		sort(A[i]+1,A[i]+N+1);
	}
	FOR(i,1,N)
		B[i] = A[i][N/2 + 1];
	sort(B+1,B+N+1);
	out << B[N/2 + 1] << endl;
}
int main()
{
	solve();
	return 0;
}
