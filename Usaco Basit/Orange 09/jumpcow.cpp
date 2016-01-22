//SORU 387
//PROGRAM C++
#include <iostream>
#include <fstream>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define all(x) x.begin(),x.end()
#define INPUT "jumpcow.in"
#define OUTPUT "jumpcow.out"
#define MAXN 150000
using namespace std;
ifstream in(INPUT);
ofstream out(OUTPUT);
int N;
int A[MAXN+5];
int DP[MAXN+5][2];
int f(int x,bool s)
{
	if(DP[x][s]) return DP[x][s];
	if(x == N + 1) return 0;
	return DP[x][s] = max(f(x+1,s),f(x+1,!s) + (s ? A[x] : -A[x]));
}
void solve()
{
	int i;
	in >> N;
	FOR(i,1,N)
		in >> A[i];
	out << f(1,1) << endl;
}
int main()
{
	solve();
	return 0;
}
