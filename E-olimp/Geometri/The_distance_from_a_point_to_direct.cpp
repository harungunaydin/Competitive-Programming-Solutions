#include <iostream>
#include <cmath>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define all(x) x.begin(),x.end()
using namespace std;
void solve()
{
	double a,b,c,x,x1,x2,y,y1,y2;
	cin >> x >> y >> x1 >> y1 >> x2 >> y2;
	a = y2-y1;
	b = x1-x2;
	c = -a*x1 - b*y1;
	printf("%.6lf\n",abs(a*x+b*y+c)/sqrt(a*a+b*b));
}
int main()
{
	solve();
	return 0;
}
