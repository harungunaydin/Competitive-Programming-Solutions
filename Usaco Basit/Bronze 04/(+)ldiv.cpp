//SORU 470
//PROGRAM C++
#include <iostream>
#include <fstream>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define TFOR(i,a,b) for(i=a; i>=b; i--)
#define INPUT "ldiv.in"
#define OUTPUT "ldiv.out"
#define all(x) x.begin(),x.end()
#define MAXN 
using namespace std;
ifstream in(INPUT);
ofstream out(OUTPUT);
int A,B;
void solve(int x,int s)
{
	if(s == 35) return;
	x*=10;
	out << x/B;
	solve(x%B,s+1);
}
int main()
{
	in >> A >> B;
	out << A/B << ".";
	A%=B;
	solve(A,0);
	return 0;
}
