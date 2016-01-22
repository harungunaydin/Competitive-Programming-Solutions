//SORU 363
//PROGRAM C++
#include <iostream>
#include <fstream>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define all(x) x.begin(),x.end()
#define INPUT "collatz.in"
#define OUTPUT "collatz.out"
using namespace std;
ifstream in(INPUT);
ofstream out(OUTPUT);
int main()
{
	int N,res=0;
	in >> N;
	while(++res,N != 1) N = (N&1) ? 3*N+1 : N/2;
	out << res << endl;
	return 0;
}
