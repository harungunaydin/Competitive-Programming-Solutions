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
bool ccw(point a,point b,point c)
{
	return (b.x-a.x)*(c.y-a.y) - (c.x-a.x)*(b.y-a.y) < 0;
}
void solve()
{
	point A,B,C,O;
	bool a,b,c;
	O.read(); A.read(); B.read(); C.read();
	a = ccw(A,B,O);
	b = ccw(B,C,O);
	c = ccw(C,A,O);
	printf("%d\n",a == b && b == c);
}
int main()
{
	solve();
	return 0;
}
