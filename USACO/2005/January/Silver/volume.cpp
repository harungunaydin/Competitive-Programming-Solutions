//SORU 444
//PROGRAM C++
#include <iostream>
#include <fstream>
#include <cmath>
#include <algorithm>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define all(x) x.begin(),x.end()
#define INPUT "volume.in"
#define OUTPUT "volume.out"
#define MAXN 10000
using namespace std;
ifstream in(INPUT);
ofstream out(OUTPUT);
int A[MAXN+5];
void solve()
{
	long long N,i,j,res=0;
	in >> N;
	FOR(i,1,N)
		in >> A[i];
	FOR(i,1,N)
		FOR(j,1,N)
			res+=abs(A[j]-A[i]);
	out << res << endl;
}
int main()
{
	solve();
	return 0;
}
