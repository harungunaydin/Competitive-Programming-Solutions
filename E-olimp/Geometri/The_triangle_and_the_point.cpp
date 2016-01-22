#include <iostream>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define all(x) x.begin(),x.end()
using namespace std;
class point
{
	public:
		int x,y;
		void read() { cin >> x >> y; }
};
double ccw(point a,point b,point c)
{
	return (b.x-a.x)*(c.y-a.y) - (b.y-a.y)*(c.x-a.x);
}
string solve()
{
	point A,B,C,O;
	double a,b,c,d;
	A.read(); B.read(); C.read(); O.read();
	a = ccw(A,B,O);
	b = ccw(B,C,O);
	c = ccw(C,A,O);
	if((a>0 && b>0 && c>0) || (a<0 && b<0 && c<0)) return "In";
	if((!a && !b) || (!a && !c) || (!b && !c)) return "On";
	if((!a && (b<0 == c<0)) || (!b && (a<0 == c<0)) || (!c && (a<0 == b<0))) return "On";
	return "Out";
}
int main()
{
	cout << solve() << endl;
	return 0;
}
