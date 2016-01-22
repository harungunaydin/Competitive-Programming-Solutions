//SORU 502
//PROGRAM C++
#include <iostream>
#include <fstream>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define INPUT "flowers.in"
#define OUTPUT "flowers.out"
#define MAXN 10000
using namespace std;
ifstream in(INPUT);
ofstream out(OUTPUT);
int M,N;
bool A[MAXN+5];
void solve()
{
	int a,b,i,j,s=0;
	in >> M >> N;
	FOR(i,1,N)
	{
		in >> a >> b;
		for(j=a; j<=M; j+=b)
			A[j] = true;
	}
	FOR(i,1,M)
		s+=!A[i];
	out << s << endl;
}
int main()
{
	solve();
	return 0;
}
