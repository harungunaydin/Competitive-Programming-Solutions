#include <iostream>
#include <cmath>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define all(x) x.begin(),x.end()
#define PI 3.141592653589793
using namespace std;
double R_Distance(double x1,double y1,double x2,double y2)
{
	return (x2-x1)*(x2-x1) + (y2-y1)*(y2-y1);
}
void solve()
{
	double u1,u2,u3,x1,x2,x3,y1,y2,y3;
	while(scanf("%lf %lf %lf %lf %lf %lf",&x1,&y1,&x2,&y2,&x3,&y3) != EOF)
	{
		u1 = R_Distance(x1,y1,x2,y2);
		u2 = R_Distance(x2,y2,x3,y3);
		u3 = R_Distance(x3,y3,x1,y1);
		u3 = (u2+u3-u1)/(2*sqrt(u2)*sqrt(u3));
		u3 = sqrt(1-u3*u3);
		printf("%.2lf\n",sqrt(u1)/u3*PI);
	}
}
int main()
{
	solve();
	return 0;
}
