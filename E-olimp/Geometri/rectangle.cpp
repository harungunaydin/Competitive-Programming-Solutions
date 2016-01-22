#include <iostream>
#include <cmath>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define all(x) x.begin(),x.end()
using namespace std;
double Distance(int x1,int y1,int x2,int y2)
{
	return sqrt((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1) );
}
void solve()
{
	int x1,x2,x3,y1,y2,y3;
	double a,b,c;
	cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
	a = Distance(x1,y1,x2,y2);
	b = Distance(x2,y2,x3,y3);
	c = Distance(x3,y3,x1,y1);
	if(a > b && a > c) { cout << x1+x2-x3 << " " << y1+y2-y3 << endl; return; }
	if(b > a && b > c) { cout << x2+x3-x1 << " " << y2+y3-y1 << endl; return; }
	if(c > a && c > b) { cout << x3+x1-x2 << " " << y3+y1-y2 << endl; return; } 
}
int main()
{
	solve();
	return 0;
}
