//SORU 539
//PROGRAM C++
#include <iostream>
#include <fstream>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define TFOR(i,a,b) for(i=a; i>=b; i--)
#define all(x) x.begin(),x.end()
#define INPUT "eatpuz.in"
#define OUTPUT "eatpuz.out"
#define MAXN 35000
using namespace std;
ifstream in(INPUT);
ofstream out(OUTPUT);
bool DP[MAXN*2];
void solve()
{
	int C,N,a,i,j;
	in >> C >> N;
	DP[0] = true;
	FOR(i,1,N)
	{
		in >> a;
		TFOR(j,C,a)
			if(DP[j-a])
				DP[j] = true;
	}
	i = C;
	while(!DP[i]) i--;
	out << i << endl;
}
int main()
{
	solve();
	return 0;
}
