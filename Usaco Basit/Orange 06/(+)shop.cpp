//SORU 365
//PROGRAM C++
#include <iostream>
#include <fstream>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define all(x) x.begin(),x.end()
#define INPUT "shop.in"
#define OUTPUT "shop.out"
#define MAXN 600
using namespace std;
ifstream in(INPUT);
ofstream out(OUTPUT);
int B[] = {1,2,4,8,20},DP[MAXN+5];
void solve()
{
	int N,i,j;
	in >> N;
	N<<=2;
	DP[0] = 1;
	FOR2(i,5)
		FOR(j,0,N-B[i])
			if(DP[j])
				DP[j+B[i]]+=DP[j];
	out << DP[N] << endl;
}
int main()
{
	solve();
	return 0;
}
