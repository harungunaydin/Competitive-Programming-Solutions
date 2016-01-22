#include <iostream>
#include <cmath>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define all(x) x.begin(),x.end()
#define MAXN 10000
#define EPS 0.0000001
using namespace std;
class point
{
	public:
		double x,y;
		point() { x=y=0; }
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
double Distance_from_origin(point a)
{
	return sqrt(a.x*a.x+a.y*a.y);
}
double Distance(segment A,point p)
{
	line d1,d2;
	d1.a = A.b.y - A.a.y;
	d1.b = A.a.x - A.b.x;
	d1.c = - d1.a*A.a.x - d1.b*A.a.y;
	
	d2.a = -d1.b;
	d2.b = d1.a;
	d2.c = 0;
	
	double det = d1.a*d2.b - d1.b*d2.a,x,y;
	if(!det) return abs(-d1.c/d1.a);
	x = - (d1.c*d2.b-d1.b*d2.c)/det;
	y = - (d1.a*d2.c-d1.c*d2.a)/det;
	if(min(A.a.x,A.b.x) <= x && x<=max(A.a.x,A.b.x) && min(A.a.y,A.b.y) <= y && y <= max(A.a.y,A.b.y) )
		return abs(d1.c) / sqrt(d1.a*d1.a+d1.b*d1.b);
	return min(Distance_from_origin(A.a),Distance_from_origin(A.b));
}
int K,L,N;
void solve()
{
	int i,s=0;
	point sifir;
	segment A;
	cin >> L >> N >> K;
	FOR(i,1,N)
	{
		A.read();
		s+=((Distance(A,sifir) - L) < EPS);
	}
	cout << (s/K) + 1 << endl;
}
int main()
{
	solve();
	return 0;
}

