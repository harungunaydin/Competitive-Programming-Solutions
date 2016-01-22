#include <iostream>
#include <cmath>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define all(x) x.begin(),x.end()
using namespace std;
double Distance(double x1,double y1,double x2,double y2)
{
	return sqrt((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1));
}
void solve()
{
	double x1,x2,x3,x4,y1,y2,y3,y4;
	cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
	printf("%.3lf %.3lf\n%.3lf %.3lf\n",(x2+x4)/2,(y2+y4)/2,Distance(x1,y1,x3,y3),Distance(x2,y2,x4,y4));
}
int main()
{
	solve();
	return 0;
}
