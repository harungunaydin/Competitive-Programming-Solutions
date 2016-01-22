#include <iostream>
#include <cmath>
#include <windows.h>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define all(x) x.begin(),x.end()
#define Distance(a,b,c,d,e,f) sqrt((d-a)*(d-a)+(e-b)*(e-b)+(f-c)*(f-c))
using namespace std;
double area(double a,double b,double c)
{
	double u = (a+b+c)/2;
	return sqrt(u*(u-a)*(u-b)*(u-c));
}
void solve()
{
	double a,b,c,d,e,f,g,x1,x2,x3,x4,y1,y2,y3,y4,z1,z2,z3,z4;
	cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2 >> x3 >> y3 >> z3 >> x4 >> y4 >> z4;
	a = Distance(x1,y1,z1,x2,y2,z2);
	b = Distance(x2,y2,z2,x3,y3,z3);
	c = Distance(x3,y3,z3,x1,y1,z1);
	d = Distance(x3,y3,z3,x4,y4,z4);
	e = Distance(x4,y4,z4,x1,y1,z1);
	f = Distance(x4,y4,z4,x2,y2,z2);
	printf("%.1lf\n",area(a,b,c) + area(f,b,d) + area(e,f,a) + area(c,d,e));
}
int main()
{
	solve();
	return 0;
}
