#include <iostream>
#include <cmath>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define all(x) x.begin(),x.end()
using namespace std;
void solve()
{
	double a,b,c,d,f,u;
	cin >> a >> b >> c >> d >> f;
	u = (a+b+f)/2;
	a = sqrt(u*(u-a)*(u-b)*(u-f));	
	u = (c+d+f)/2;
	printf("%.4lf\n",a+sqrt(u*(u-c)*(u-d)*(u-f)));
}
int main()
{
	solve();
	return 0;
}
