#include <iostream>
#include <cmath>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define all(x) x.begin(),x.end()
using namespace std;
class point
{
	public:
		double x,y;
		void read() { cin >> x >> y; }
};
class segment
{
	public:
		point a,b;
		void read() { a.read(); b.read(); }
};
class line
{
	public:
		double a,b,c;
};
double Distance(point a,point b)
{
	return sqrt((b.x-a.x)*(b.x-a.x) + (b.y-a.y)*(b.y-a.y));
}
point make_point(double x,double y)
{
	point temp;
	temp.x = x; temp.y = y;
	return temp;
}
double Distance(segment A,point B)
{
	line d1,d2;
	d1.a = A.b.y - A.a.y;
	d1.b = A.a.x - A.b.x;
	d1.c = -d1.a*A.a.x - d1.b*A.a.y;
	
	d2.a = -d1.b;
	d2.b = d1.a;
	d2.c = -d2.a*B.x - d2.b*B.y;
	
	double det = d1.a*d2.b - d1.b*d2.a,x,y;
	x = - (d1.c*d2.b - d1.b*d2.c)/det;
	y = - (d1.a*d2.c - d1.c*d2.a)/det;
	
	if(min(A.a.x,A.b.x) <= x && x <= max(A.a.x,A.b.x) && min(A.a.y,A.b.y) <= y && y <= max(A.a.y,A.b.y))
		return Distance(B,make_point(x,y));
	return min(Distance(B,A.a),Distance(B,A.b));
}
void solve()
{
	segment A;
	point C;
	double a,b,L;
	A.read(); C.read(); cin >> L;
	a = Distance(A,C) - L;
	b = max(Distance(C,A.a),Distance(C,A.b)) - L;
	if(a <= 0) a = 0;
	if(b <= 0) b = 0;
	printf("%.6lf\n%.6lf\n",a,b);
}
int main()
{
	solve();
	return 0;
}
