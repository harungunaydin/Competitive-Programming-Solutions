//SORU 1163
//PROGRAM C++
#include <iostream>
#include <fstream>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define all(x) x.begin(),x.end()
#define INPUT "buyhay.in"
#define OUTPUT "buyhay.out"
#define MAXN 100000
#define INF 1000000000
using namespace std;
ifstream in(INPUT);
ofstream out(OUTPUT);
int DP[MAXN+5];
void solve()
{
	int M,N,a,b,i,j,maxi=0,mini=INF;
	in >> N >> M;
	DP[0] = 1;
	FOR(i,1,N)
	{
		in >> a >> b;
		maxi = max(maxi,a);
		for(j=0; j<=M; j++)
			if(DP[j] && (DP[j] + b < DP[j+a] || !DP[j+a]))
				DP[j+a] = DP[j] + b;
	}
	maxi = M + maxi;
	FOR(i,M,maxi)
		if(DP[i] && DP[i] < mini)
			mini = DP[i];
	out << mini-1 << endl;
}
int main()
{
	solve();
	return 0;
}
