#include <iostream>
#include <cstdio>
#include <cmath>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define all(x) x.begin(),x.end()
using namespace std;
bool esit_mi(double a,double b)
{
	return abs(a - b) < 0.000000001;
}
void solve()
{
	double d,m,n,r,x,y,x1,y1,x2,y2;
	cin >> r >> x >> y;
	cin >> x1 >> y1 >> x2 >> y2;
	if(x1 == x2)
		d = abs(x - x1);
	else
	{
		m = (y2-y1)/(x2-x1);
		n = y1 - m*x1;
		d = (abs(m*x-y+n))/(sqrt(m*m+1));
	}
	if(esit_mi(d,r)) printf("0\n");
	else if(d > r) printf("-1\n");
	else printf("%.5lf\n",2*sqrt(r*r - d*d));
}
int main()
{
	solve();
	return 0;
}
