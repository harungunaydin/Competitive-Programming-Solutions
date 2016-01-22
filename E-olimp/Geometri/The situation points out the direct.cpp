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
class line
{
	public :
		double a,b,c;
		void read() { cin >> a >> b >> c; }
};
bool ccw(point a,point b,point c)
{
	return (b.x-a.x)*(c.y-a.y) - (b.y-a.y)*(c.x-a.x) < 0;
}
string solve()
{
	line d;
	point a,b,e,f;
	a.read(); b.read(); d.read();
	if(!d.b) 
	{  
		d.c/=-d.a;
		return ((a.x<d.c && b.x<d.c) || (a.x==d.c && b.x==d.c) || (a.x>d.c && b.x>d.c)) ? "YES" : "NO";
	}
	e.x = 0; e.y = -d.c/d.b;
	f.x = 1; f.y = (-d.c-d.a)/d.b;
	return ccw(e,f,a) == ccw(e,f,b) ? "YES" : "NO";
}
int main()
{
	cout << solve() << endl;
	return 0;
}
