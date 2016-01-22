#include <iostream>
#include <cmath>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define all(x) x.begin(),x.end()
using namespace std;
const double PI = acos(-1);
double solve()
{
	double x,y;
	cin >> x >> y;
	if(y>=0)
	{
		if(x > 0) return atan(y/x);
		if(x < 0) return PI - atan(y/abs(x));
		return PI/2;
	}
	if(x < 0) return atan(abs(y)/abs(x)) + PI;
	if(x > 0) return 2*PI - atan(abs(y)/abs(x));
	return 1.5*PI;
}
int main()
{
	double res;
	res = solve();
	if(res >=0 && res<=0) res = 0;
	printf("%.6lf\n",res);
	return 0;
}
