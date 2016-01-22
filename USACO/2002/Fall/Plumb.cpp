//SORU 321
//PROGRAM C++
#include <iostream>
#include <fstream>
#include <algorithm>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define TFOR(i,a,b) for(i=a; i>=b; i--)
#define all(x) x.begin(),x.end()
#define INPUT "plumb.in"
#define OUTPUT "plumb.out"
#define f first
#define s second
#define MAXN 1000000
#define OO 1000000000
#define MIN(a,b) ((a<b) ? a : b)
using namespace std;
ifstream in(INPUT);
ofstream out(OUTPUT);
int DP[MAXN+5];
void solve()
{
	int D,P,a,b,i,j;
	in >> D >> P;
	DP[0] = OO;
	FOR(i,1,P)
	{
		in >> a >> b;
		TFOR(j,D,a)
			if(MIN(DP[j-a],b) > DP[j])
				DP[j] = MIN(DP[j-a],b);
	}
	out << DP[D] << endl;
}
int main()
{
	solve();
	return 0;
}
