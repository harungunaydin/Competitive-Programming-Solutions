//SORU 1011
//PROGRAM C++
#include <iostream>
#include <fstream>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define TFOR(i,a,b) for(i=a; i>=b; i--)
#define all(x) x.begin(),x.end()
#define INPUT "charm.in"
#define OUTPUT "charm.out"
#define MAXN 13000
using namespace std;
ifstream in(INPUT);
ofstream out(OUTPUT);
int DP[MAXN+5];
void solve()
{
	int M,N,a,b,i,j;
	in >> N >> M;
	FOR(i,1,N)
	{
		in >> a >> b;
		TFOR(j,M,a)
			if(DP[j-a] + b > DP[j])
				DP[j] = DP[j-a] + b;
	}
	i = M;
	while(!DP[i]) i--;
	out << DP[i] << endl;
}
int main()
{
	solve();
	return 0;
}
