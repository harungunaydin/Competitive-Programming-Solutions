#include <iostream>
#include <cmath>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define all(x) x.begin(),x.end()
using namespace std;
void solve()
{
	double S,a,d;
	cin >> S >> a;
	d = a*a + 8*S;
	printf("%.2lf\n",(sqrt(d)-a)/2);
}
int main()
{
	solve();
	return 0;
}
