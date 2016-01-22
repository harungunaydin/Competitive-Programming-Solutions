#include <iostream>
#include <cmath>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define all(x) x.begin(),x.end()
using namespace std;
const double PI = acos(-1);
double solve()
{
	double a,b,c,r,t;
	cin >> a >> r;
	if(r <= a/2) return PI*r*r;
	else if(r>=a/sqrt(2.0)){ return a*a; }
	a/=2;
	t = sqrt(r*r-a*a);
	b = a*t;
	c = ((atan(t/a)*180)/PI);
	c = (PI*r*r*c)/180 - b;
	return PI*r*r - c*4;
}
int main()
{
	printf("%.6lf\n",solve());
	return 0;
}
