#include <iostream>
#include <cmath>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define all(x) x.begin(),x.end()
using namespace std;
void solve()
{
	double x,y,a,b,c;
	cin >> x >> y >> a >> b >> c;
	printf("%.6lf\n",abs(a*x+b*y+c)/sqrt(a*a+b*b));
}
int main()
{
	solve();
	return 0;
}
