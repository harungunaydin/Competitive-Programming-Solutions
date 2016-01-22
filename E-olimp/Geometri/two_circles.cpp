#include <iostream>
#include <cmath>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define all(x) x.begin(),x.end()
#define EPS 0.0000000001
using namespace std;
bool esit(double a,double b)
{
	return fabs(a - b) < EPS;
}
int solve()
{
	double x1,y1,r1,x2,y2,r2;
	cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
	double a,b,c;
	a = x2-x1; a*=a;
	b = y2-y1; b*=b;
	c = r1 + r2; c*=c;
	if(x1 == x2 && y1 == y2 &&  r1 == r2) return -1;
	if(sqrt(a+b) > r1+r2) return 0;
	if(esit(sqrt(a+b),r1+r2)) return 1;
	if(sqrt(a+b)+r1==r2 || sqrt(a+b)+r2==r1) return 1;
	if(sqrt(a+b) < r1+r2 && (sqrt(a+b)+r1 < r2 || sqrt(a+b)+r2<r1) ) return 0;
	return 2;
}
int main()
{
	cout << solve() << endl;
	return 0;
}
