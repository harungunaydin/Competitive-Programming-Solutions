#include <iostream>
#include <cmath>
#define EPS 0.000000001
using namespace std;
const double PI = acos(-1);
class point
{
	public:
		int x,y;
		point() { x = y = 0; }
		point(int a,int b) { x = a; y = b; }
		void read() { cin >> x >> y; }
};
class point_d
{
	public:
		double x,y;
};
class line
{
	public:
		double a,b,c;
};
bool is_equal(double a,double b)
{
	return abs(a-b) < EPS;
}
double Distance(point a,point b)
{
	return sqrt((b.x-a.x)*(b.x-a.x) + (b.y-a.y)*(b.y-a.y));
}
point make_point(int a,int b)
{
	point temp(a,b);
	return temp;
}
line make_line_from_two_points(point a,point_d b)
{
	line temp;
	temp.a = b.y - a.y;
	temp.b = a.x - b.x;
	temp.c = -temp.a*a.x - temp.b*a.y;
	return temp;
}
double ccw(point a,point b,point c)
{
	return (b.x-a.x)*(c.y-a.y) - (b.y-a.y)*(c.x-a.x);
}
line solve()
{
	point X,Y,Z;
	point_d P;
	double a,b;
	X.read(); Y.read(); Z.read();
	a = Distance(X,Y);
	b = Distance(X,Z);
	P.x = (Z.x + X.x + ((Y.x-X.x)/a)*b)/2;
	P.y = (Z.y + X.y + ((Y.y-X.y)/a)*b)/2;
	return make_line_from_two_points(X,P);
}
int main()
{
	line res;
	res = solve();
	printf("%.3lf %.3lf %.3lf\n",res.a,res.b,res.c);
	return 0;
}
