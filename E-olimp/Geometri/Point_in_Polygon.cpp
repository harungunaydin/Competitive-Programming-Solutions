#include <iostream>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define all(x) x.begin(),x.end()
#define MAXN 100000
using namespace std;
class point
{
	public:
		double x,y;
		void read() { scanf("%lf %lf",&x,&y); }
}p[MAXN+5];
class triangle
{
	public:
		point a,b,c;
		void read() { a.read(); b.read(); c.read(); }
};
double ccw(point a,point b,point c)
{
	return (b.x-a.x)*(c.y-a.y) - (b.y-a.y)*(c.x-a.x);
}
triangle make_triangle(point a,point b,point c)
{
	triangle temp;
	temp.a = a; temp.b = b; temp.c = c;
	return temp;
}
bool is_point_in_triangle(triangle A,point B)
{
	double a,b,c;
	a = ccw(A.a,A.b,B);
	b = ccw(A.b,A.c,B);
	c = ccw(A.c,A.a,B);
	if((a>0 && b>0 && c>0) || (a<0 && b<0 && c<0)) return 1;
	if((!a && !b) || (!a && !c) || (!b && !c)) return 1;
	if((!a && (b<0 == c<0)) || (!b && (a<0 == c<0)) || (!c && (a<0 == b<0))) return 1;
	return 0;
}
string solve()
{
	point A;
	int N,i,s=0;
	double a;
	scanf("%d",&N);
	A.read();
	FOR(i,1,N)
		p[i].read();
	FOR(i,2,N-1)
		if(is_point_in_triangle(make_triangle(p[1],p[i],p[i+1]),A))
		{
			a = (p[i].x-p[1].x)*(p[i+1].y-p[i].y) - (p[i].y-p[1].y)*(p[i+1].x-p[i].x);
			if(a > 0) s++;
			if(a < 0) s--;
		}
	return (!s) ? "NO" : "YES";
}
int main()
{
	cout << solve() << endl;
	return 0;
}
