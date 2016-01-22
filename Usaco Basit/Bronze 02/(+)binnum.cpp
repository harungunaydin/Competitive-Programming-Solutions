//SORU 447
//PROGRAM C++
#include <iostream>
#include <fstream>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define INPUT "binnum.in"
#define OUTPUT "binnum.out"
using namespace std;
ifstream in(INPUT);
ofstream out(OUTPUT);
int N;
void solve(int x)
{
	if(!x) return;
	solve(x>>1);
	out << (x&1);
}
int main()
{
	in >> N;
	if(!N) out << 0;
	solve(N);
	out << endl;
	return 0;
}
