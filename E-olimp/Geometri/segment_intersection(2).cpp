#include <iostream>
#include <cmath>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define all(x) x.begin(),x.end()
#define EPS 0.000000001
using namespace std;
const double PI = acos(-1);
bool esit(double a,double b)
{
	return abs(a-b) < EPS;
}
class segment
{
	public :
		double A,B,C,x1,y1,x2,y2;
		void read() { cin >> x1 >> y1 >> x2 >> y2; }
		double egim() { return (y2-y1)/(x2-x1); }
		void dondur(double a)
		{
			a = (a*PI)/180;
			x1 = x1*cos(a) + y1*sin(a);
			x2 = x2*cos(a) + y2*sin(a);
			y1 = x1*sin(a) - y1*cos(a);
			y2 = x2*sin(a) - y2*cos(a);
		}
};
string solve()
{
	segment a,b;
	double m;
	a.read(); b.read();
	if(!esit(b.x1,b.x2))
	{
		m = (atan(b.egim())*180)/PI;
		a.dondur(m-90);
		b.dondur(m-90);
	}
	return "123";
}
int main()
{
	cout << solve() << endl;
	system("PAUSE");
	return 0;
}
