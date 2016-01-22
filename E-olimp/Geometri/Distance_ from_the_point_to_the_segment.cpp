#include <iostream>
#include <cmath>
using namespace std;
class point
{
	public:
		double x,y;
		void read() { cin >> x >> y; }
};
class line
{
	public:
		double a,b,c;
};
double Distance(double a,double b,double c,double d)
{
	return (c-a)*(c-a) + (d-b)*(d-b);
}
double solve()
{
	point A,B,C;
	line d,d2;
	double det,x,y;
	A.read(); B.read(); C.read();
	
	d.a = C.y - B.y;
	d.b = B.x - C.x; 
	d.c = -d.a*B.x - d.b*B.y;
	
	d2.a = -d.b;
	d2.b = d.a;
	d2.c = -d2.a*A.x - d2.b*A.y;
	
	det = d.a*d2.b - d.b*d2.a;
	x = -(d.c*d2.b - d.b*d2.c)/det;
	y = -(d.a*d2.c - d.c*d2.a)/det;
	if(min(B.x,C.x)<=x && x<=max(B.x,C.x) && min(B.y,C.y)<=y && y<=max(B.y,C.y)) return Distance(x,y,A.x,A.y);
	return min(Distance(A.x,A.y,B.x,B.y),Distance(A.x,A.y,C.x,C.y));
}
int main()
{
	printf("%.6lf\n",sqrt(solve()));
	return 0;
}
