#include <iostream>
#include <cmath>
#include <vector>
#define EPS 0.000000001
using namespace std;
typedef pair <double,double> pdd;
vector <pdd> V;
class point
{
	public:
		double x,y;
		point() { x = y = 0; }
		point(double a,double b) { x = a; y = b; }
		void read() { cin >> x >> y; }
};
class segment
{
	public:
		point a,b;
		segment() {  }
		segment(point x,point y) { a = x; b = y; }
};
class circle
{
	public:
		point m;
		double r;
		void read() { m.read(); cin >> r; }
};
class line
{
	public:
		double a,b,c;
};
segment make_segment(point a,point b)
{
	segment t(a,b);
	return t;
}
bool esit(double a,double b)
{
	return abs(a-b) < EPS;
}
bool buyuk_esit(double a,double b)
{
	return a > b || esit(a,b);
}
point make_point(double a,double b)
{
	point t(a,b);
	return t;
}
line make_line_from_two_points(point a,point b)
{
	line t;
	t.a = b.y - a.y;
	t.b = a.x - b.x;
	t.c = -t.a*a.x - t.b*a.y;
	return t;
}
double Distance(point a,point b)
{
	return sqrt((b.x-a.x)*(b.x-a.x) + (b.y-a.y)*(b.y-a.y));
}
double Distance(point a,line d)
{
	return abs(d.a*a.x+d.b*a.y+d.c)/sqrt(d.a*d.a+d.b*d.b);
}
void solve(circle C,segment B)
{
	line d = make_line_from_two_points(B.a,B.b);
}
int main()
{
	circle c;
	point A,B,C;
	double a;
	c.read(); A.read(); B.read(); C.read();
	solve(C,make_segment(A,B));
	solve(C,make_segment(B,C));
	solve(C,make_segment(C,A));
	system("PAUSE");
	return 0;
}
