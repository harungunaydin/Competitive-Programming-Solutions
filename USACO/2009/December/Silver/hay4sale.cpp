//SORU 1153
//PROGRAM C++
#include <iostream>
#include <fstream>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define INPUT "hay4sale.in"
#define OUTPUT "hay4sale.out"
#define MAXN 100000
using namespace std;
ifstream in(INPUT);
ofstream out(OUTPUT);
int MAXI,N;
int DP[MAXN+5];
void solve()
{
	int c,i,j;
	in >> MAXI >> N;
	DP[0] = true;
	FOR(i,1,N)
	{
		in >> c;
		for(j=MAXI; j>=0; j--)
			if(DP[j])
				DP[j+c] = true;
	}
	j = MAXI;
	while(!DP[j]) j--;
	out << j << endl;
}
int main()
{
	solve();
	return 0;
}
