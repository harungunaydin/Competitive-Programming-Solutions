//SORU 469
//PROGRAM C++
#include <iostream>
#include <fstream>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define INPUT "cnums.in"
#define OUTPUT "cnums.out"
using namespace std;
ifstream in(INPUT);
ofstream out(OUTPUT);
int s,k;
void f(int x)
{
	if(!x) { s++; return; }
	k+=(x&1);
	if(k > 4) return;
	f(x>>1);
}
void solve()
{
	int a,b,i;
	in >> a >> b;
	FOR(i,a,b)
	{
		k = 0;
		f(i);
	}
	out << s << endl;
}
int main()
{
	solve();
	return 0;
}
