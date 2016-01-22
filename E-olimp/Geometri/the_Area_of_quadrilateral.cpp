#include <iostream>
#include <cmath>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define f first
#define s second
using namespace std;
class point
{
	public :
		int x,y;
		void read() { cin >> x >> y; }
};
void solve()
{
	point a,b,c,d;
	double res1,res2;
	a.read(); b.read(); c.read(); d.read();
	res1 = abs((a.x*b.y+b.x*c.y+c.x*a.y) - (a.y*b.x+b.y*c.x+c.y*a.x));
	res2 = abs((a.x*c.y+c.x*d.y+d.x*a.y) - (a.y*c.x+c.y*d.x+d.y*a.x));
	printf("%0.lf\n",(res1 + res2)/2);
}
int main()
{
	solve();
	return 0;
}
