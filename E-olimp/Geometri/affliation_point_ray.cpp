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
class segment
{
	public:
		point a,b;
		void read() { a.read(); b.read(); }
};
double ccw(point a,point b,point c)
{
	return (b.x-a.x)*(c.y-a.y) - (b.y-a.y)*(c.x-a.x);
}
string solve()
{
	segment A;
	point b;
	b.read(); A.read();
	if(ccw(A.a,A.b,b)) return "NO";
	A.b.x+=(A.b.x-A.a.x)*100000;
	A.b.y+=(A.b.y-A.a.y)*100000;
	int minix = min(A.a.x,A.b.x),maxix=max(A.a.x,A.b.x),miniy=min(A.a.y,A.b.y),maxiy=max(A.a.y,A.b.y);
	return (minix<=b.x && b.x<=maxix && miniy<=b.y && b.y <= maxiy) ? "YES" : "NO";
}
int main()
{
	cout << solve() << endl;
	return 0;
}
