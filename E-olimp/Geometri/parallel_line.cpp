#include <iostream>
#include <cmath>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define all(x) x.begin(),x.end()
using namespace std;
void solve()
{
	double a,b,c,d,e;
	cin >> a >> b >> c >> d;
	e = sqrt(a*a+b*b);
	printf("%.6lf %.6lf %.6lf\n%.6lf %.6lf %.6lf\n",a,b,c-e*d,a,b,c+e*d);
}
int main()
{
	solve();
	return 0;
}
