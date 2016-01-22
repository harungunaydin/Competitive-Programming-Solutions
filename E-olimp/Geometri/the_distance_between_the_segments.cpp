#include <iostream>
#include <cmath>
#define EPS 0.000000001
using namespace std;
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
		void read() { a.read(); b.read(); }
};
class line
{
	public:
		double a,b,c;
};
inline point make_point(double a,double b)
{
	point t(a,b);
	return t;
}
inline point intersection_of_two_lines(line d1,line d2)
{
	double det = d1.a*d2.b - d1.b*d2.a;
	return make_point(-(d1.c*d2.b-d1.b*d2.c)/det,-(d1.a*d2.c-d1.c*d2.a)/det);
}
inline bool is_on_segment(point a,segment b)
{
	return min(b.a.x,b.b.x) <= a.x && a.x <= max(b.a.x,b.b.x) && min(b.a.y,b.b.y) <= a.y && a.y <= max(b.a.y,b.b.y);
}
inline line make_line_from_two_points(point a,point b)
{
	line t;
	t.a = b.y - a.y;
	t.b = a.x - b.x;
	t.c = -t.a*a.x - t.b*a.y;
	return t;
}
inline double Distance(point a,point b)
{
	return sqrt((b.x-a.x)*(b.x-a.x)+(b.y-a.y)*(b.y-a.y));
}
inline double Distance(point a,segment B)
{
	line d1 = make_line_from_two_points(B.a,B.b),d2;
	d2.a = -d1.b;
	d2.b = d1.a;
	d2.c = -d2.a*a.x - d2.b*a.y;
	point p = intersection_of_two_lines(d1,d2);
	if(is_on_segment(p,B)) return Distance(a,p);
	return min(Distance(a,B.a),Distance(a,B.b));	
}
inline double segment_intersection(segment A,segment B)
{
	line d1,d2;
	d1 = make_line_from_two_points(A.a,A.b);
	d2 = make_line_from_two_points(B.a,B.b);
	point p = intersection_of_two_lines(d1,d2);
	if(is_on_segment(p,A) && is_on_segment(p,B)) return 0;
	return min(min(Distance(A.a,B),Distance(A.b,B)),min(Distance(B.a,A),Distance(B.b,A)));
}
inline double ccw(point a,point b,point c)
{
	return (b.x-a.x)*(c.y-a.y) - (b.y-a.y)*(c.x-a.x);
}
inline bool is_equal(double a,double b)
{
	return abs(a-b) < EPS;
}
double solve()
{
	line d1,d2;
	segment A,B;
	A.read(); B.read();
	d1 = make_line_from_two_points(A.a,A.b);
	d2 = make_line_from_two_points(B.a,B.b);
	if(is_equal(d1.a*d2.b,d2.a*d1.b))
	{
		if(is_equal(ccw(A.a,A.b,B.a),0))
			if(is_on_segment(B.a,A) || is_on_segment(B.b,A))
				return 0;
		return min(min(Distance(A.a,B.a),Distance(A.a,B.b)),min(Distance(A.b,B.a),Distance(A.b,B.b)));
	}
	return segment_intersection(A,B);
}
int main()
{
	printf("%.6lf\n",solve());
	return 0;
}
