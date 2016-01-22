#include <iostream>
#include <cmath>
using namespace std;
class point
{
	public:
		double x,y;
		point() { x = y = 0; }
		point(double a,double b) { x = a; y = b; }
		void read() { scanf("%lf %lf",&x,&y); }
		void print() { printf("%.6lf %.6lf\n",x,y); }
};
class triangle
{
	public:
		point a,b,c;
		void read() { a.read(); b.read(); c.read(); }
};
class line
{
	public:
		double a,b,c;
		line() {  }
		line(double x,double y,double z) { a = x; b = y; c = z; }
};
point make_point(double x,double y)
{
	point p(x,y);
	return p;
}
line make_line(double a,double b,double c)
{
	line l(a,b,c);
	return l;
}
line make_line_from_two_points(point a,point b)
{
	line t;
	t.a = b.y - a.y;
	t.b = a.x - b.x;
	t.c = -t.a*a.x - t.b*a.y;
	return t;
}
point median(point a,point b)
{
	return make_point((a.x+b.x)/2,(a.y+b.y)/2);
}
double Distance(point a,point b)
{
	return sqrt((b.x-a.x)*(b.x-a.x) + (b.y-a.y)*(b.y-a.y));
}
double circumference_of_the_triangle(triangle t)
{
	double c;
	c = Distance(t.a,t.b);
	c+= Distance(t.b,t.c);
	c+= Distance(t.c,t.a);
	return c;
}
point intersection_of_two_lines(line d1,line d2)
{
	double det = d1.a*d2.b - d1.b*d2.a;
	return make_point(-(d1.c*d2.b-d1.b*d2.c)/det,-(d1.a*d2.c-d1.c*d2.a)/det);
}
point ic_teget_cemberin_merkezi(triangle t)
{
	line d1,d2;
	point A,B,C,P1,P2,X,Y,Z;
	double ab,ac,bc,c,m1,m2,x,y,z;
	A = t.a; B = t.b; C = t.c;
	c = circumference_of_the_triangle(t)/2;
	ab = Distance(A,B);
	ac = Distance(A,C);
	bc = Distance(B,C);
	x = c - bc;
	y = c - ac;
	z = c - ab;
	X.x = B.x + ((A.x - B.x)/ab)*y;
	X.y = B.y + ((A.y - B.y)/ab)*y;
	Y.x = C.x + ((A.x - C.x)/ac)*z;
	Y.y = C.y + ((A.y - C.y)/ac)*z;
	Z.x = B.x + ((C.x - B.x)/bc)*y;
	Z.y = B.y + ((C.y - B.y)/bc)*y;
	P1 = median(X,Y); P2 = median(X,Z);
	m1 = (Y.x - X.x) / (X.y - Y.y);
	m2 = (Z.x - X.x) / (X.y - Z.y);
	d1 = make_line(m1,-1,P1.y-m1*P1.x);
	d2 = make_line(m2,-1,P2.y-m2*P2.x);
	return intersection_of_two_lines(d1,d2);
}
int main()
{
	triangle t;
	t.read();
	ic_teget_cemberin_merkezi(t).print();
	return 0;
}
