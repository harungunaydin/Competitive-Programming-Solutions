//SORU 443
//PROGRAM C++
#include <iostream>
#include <fstream>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define INPUT "sumset.in"
#define OUTPUT "sumset.out"
#define MOD 1000000000
#define MAXN 2000000
using namespace std;
ifstream in(INPUT);
ofstream out(OUTPUT);
int N;
long long DP[MAXN+5];
int pow[] = {1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536,131072,262144,524288};
void solve()
{
	int i,j;
	in >> N;
	FOR(i,0,19)
	{
		DP[pow[i]]++;
		for(j=0; j<=N; j++)
			DP[j+pow[i]]+=DP[j]%MOD;
		DP[j+pow[i]]%=MOD;
	}
	out << DP[N]%MOD<< endl;
}
int main()
{
	solve();
	return 0;
}
