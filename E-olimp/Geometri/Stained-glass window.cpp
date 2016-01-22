#include <iostream>
#include <cmath>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define all(x) x.begin(),x.end()
using namespace std;
const double PI = acos(-1);
void solve()
{
	double r;
	char a,b,c;
	double a1,b1,c1;
	cin >> r;
	cin >> a >> a >> a;
	cin >> b >> b >> b;
	cin >> c >> c >> c;
	a-='0'; b-='0'; c-='0';
	a1 = a*r*r*(PI-2)/8;
	b1 = b*r*r/2;
	c1 = c*r*r*(PI-2)/8;
	printf("%.3lf %.3lf %.3lf\n",a1,b1,c1);
}
int main()
{
	solve();
	return 0;
}
