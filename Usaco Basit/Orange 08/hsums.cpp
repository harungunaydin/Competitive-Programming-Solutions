//SORU 380
//PROGRAM C++
#include <iostream>
#include <fstream>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define all(x) x.begin(),x.end()
#define INPUT "hsums.in"
#define OUTPUT "hsums.out"
#define MAXN 10000000
using namespace std;
ifstream in(INPUT);
ofstream out(OUTPUT);
int DP[MAXN+5];
void solve()
{
	int N,a,i,j,n,res=1;
	in >> N;
	n = N;
	FOR(i,1,N)
		DP[i] = DP[i-1] + i;
	FOR(i,1,N)
		FOR(j,i+1,N)
		{
			a = DP[j] - DP[i-1];
			res+=(a == N);
			if(a > N)
				break;
		}
	out << res << endl;
}
int main()
{
	solve();
	return 0;
}
