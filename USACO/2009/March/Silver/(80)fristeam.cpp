//SORU 1229
//PROGRAM C++
#include <iostream>
#include <fstream>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define TFOR(i,a,b) for(i=a; i>=b; i--)
#define all(x) x.begin(),x.end()
#define INPUT "fristeam.in"
#define OUTPUT "fristeam.out"
#define MAXN 10000000
#define MOD 100000000
using namespace std;
ifstream in(INPUT);
ofstream out(OUTPUT);
int DP[MAXN+5];
void solve()
{
	int F,N,a,i,j;
	cin >> N >> F;
	DP[0] = 1;
	FOR(i,1,N)
	{
		cin >> a;
		a%=F;
		FOR(j,0,F)
			DP[j+a] = (DP[j+a] + DP[j])%MOD;
	}
	DP[0] = true;
	cout << (DP[F]-1 + MOD) % MOD << endl;
}
int main()
{
	solve();
	return 0;
}
