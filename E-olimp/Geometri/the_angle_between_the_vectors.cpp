#include <iostream>
#include <cmath>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define all(x) x.begin(),x.end()
using namespace std;
void solve()
{
	double d,u1,u2,x1,x2,y1,y2;
	cin >> x1 >> y1 >> x2 >> y2;
	d = (x2-x1)*(x2-x1) + (y2-y1)*(y2-y1);
	u1 = x1*x1 + y1*y1;
	u2 = x2*x2 + y2*y2;
	u1 = acos((u1+u2-d)/(2*sqrt(u1)*sqrt(u2)));
	printf("%.5lf\n",u1);
}
int main()
{
	solve();
	return 0;
}
