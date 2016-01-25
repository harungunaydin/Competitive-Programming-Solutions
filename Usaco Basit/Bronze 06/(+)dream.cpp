//SORU 540
//PROGRAM C++
#include <iostream>
#include <fstream>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define all(x) x.begin(),x.end()
#define INPUT "dream.in"
#define OUTPUT "dream.out"
using namespace std;
ifstream in(INPUT);
ofstream out(OUTPUT);
int res[10];
void solve()
{
	int a,b,i,t;
	in >> a >> b;
	FOR(i,a,b)
	{
		t = i;
		while(t)
		{
			res[t%10]++;
			t/=10;
		}
	}
	FOR2(i,10)
		out << res[i] << " ";
}
int main()
{
	solve();
	return 0;
}
