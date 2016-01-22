//SORU 364
//PROGRAM C++
#include <iostream>
#include <fstream>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define all(x) x.begin(),x.end()
#define INPUT "cowfib.in"
#define OUTPUT "cowfib.out"
using namespace std;
ifstream in(INPUT);
ofstream out(OUTPUT);
int solve()
{
	int K,a,b,s=0,t;
	in >> a >> b >> K;
	t = a;
	while(t) { t/=10; ++s; } 
	while(1)
	{
		t = b;
		while(t)
		{
			t/=10;
			s++;
		}
		if(s >= K)
		{
			FOR(t,1,s-K) b/=10;
			return b%10;
		}
		a+=b;
		swap(a,b);
	}
}
int main()
{
	out << solve() << endl;
	return 0;
}
