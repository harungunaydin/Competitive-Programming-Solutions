#include <iostream>
#include <cmath>
#define EPS 0.0000000001
using namespace std;
class point
{
	public:
		double x,y;
		point() { x = y = 0; }
		point(double a,double b) { x = a; y = b; }
		void read() { scanf("%lf %lf",&x,&y); }
};
class segment
{
	public:
		point a,b;
		segment() {  }
		segment(point x,point y) { a = x; b =y; }
		void read() { a.read(); b.read(); }
};
class line
{
	public:
		double a,b,c;
		double egim() { return -a/b; }
};
bool esit_mi(double a,double b)
{
	return abs(a-b) < EPS;
}
bool is_b(double a,double b,double c)
{
	return (a<=b && b<=c);
}
segment make_segment(point a,point b)
{
	segment temp(a,b);
	return temp;
}
point make_point(double a,double b)
{
	point temp(a,b);
	return temp;
}
line make_line_from_segment(segment A)
{
	 line d;
	 d.a = A.b.y - A.a.y;
	 d.b = A.a.x - A.b.x;
	 d.c = -d.a*A.a.x - d.b*A.a.y;
	 return d;
}
point intersection_of_two_lines(line d1,line d2)
{
	double det=d1.a*d2.b-d1.b*d2.a;
	return make_point(-(d1.c*d2.b-d1.b*d2.c)/det,-(d1.a*d2.c-d1.c*d2.a)/det);
}
double ccw(point a,point b,point c)
{
	return (b.x-a.x)*(c.y-a.y) - (b.y-a.y)*(c.x-a.x);
}
string solve()
{
	line d1,d2,temp;
	segment A,B;
	point a,b,c,d,e;
	A.read(); B.read();
	d1 = make_line_from_segment(A);
	d2 = make_line_from_segment(B);
	a = A.a; b = A.b; c = B.a; d = B.b;
	if(d1.a*d2.b == d2.a*d1.b)
	{
		if(esit_mi(ccw(a,b,c),0))
			return (max(a.x,b.x) < min(c.x,d.x) || max(c.x,d.x) < min(a.x,b.x) || 
			max(a.y,b.y) < min(c.y,d.y) || max(c.y,d.y) < min(a.y,b.y)) ? "NO" : "YES";
		return "NO";
	}
	e = intersection_of_two_lines(d1,d2);
	return (is_b(min(a.x,b.x),e.x,max(a.x,b.x)) && is_b(min(a.y,b.y),e.y,max(a.y,b.y)) && 
	is_b(min(c.x,d.x),e.x,max(c.x,d.x)) && is_b(min(c.y,d.y),e.y,max(c.y,d.y))) ? "YES" : "NO";
}
int main()
{
	cout << solve() << endl;
	return 0;
}
