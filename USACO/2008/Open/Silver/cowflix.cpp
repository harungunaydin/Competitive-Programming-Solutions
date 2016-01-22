//SORU 1051
//PROGRAM C++
#include <iostream>
#include <fstream>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define INPUT "cowflix.in"
#define OUTPUT "cowflix.out"
#define MAXN 16
using namespace std;
ifstream in(INPUT);
ofstream out(OUTPUT);
int MAX,N;
int A[MAXN+5];
int DP[10005];
void solve()
{
	int i,j;
	in >> MAX >> N;
	FOR(i,1,N)
		in >> A[i];
	DP[0] = true;
	for(i=1; i<=N; i++)
		for(j=MAX; j>=0; j--)
			if(DP[j])
				DP[j+A[i]] = true;
	i = MAX;
	while(!DP[i]) i--;
	out << i << endl;
}
int main()
{
	solve();
	return 0;
}
