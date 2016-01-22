//SORU 435
//PROGRAM C++
#include <iostream>
#include <fstream>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define RFOR(i,a,b) for(i=a; i>=b; i--)
#define all(x) x.begin(),x.end()
#define INPUT "fcount.in"
#define OUTPUT "fcount.out"
#define MAXN 2000
using namespace std;
ifstream in(INPUT);
ofstream out(OUTPUT);
int T[MAXN+5];
void solve()
{
	int D,F1,F2,N,a,b,i,j,s;
	in >> N >> F1 >> F2 >> D;
	FOR(i,1,N)
	{
		in >> a >> b;
		FOR(j,a,b)
			T[j]++;
	}
	RFOR(i,D,1)
	{	
		s = F1;
		FOR(j,i,D)
			s-=T[j];
		if(s == F2) break;
	}
	out << i << endl;
}
int main()
{
	solve();
	return 0;
}
