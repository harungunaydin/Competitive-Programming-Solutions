#include <iostream>
using namespace std;
void solve()
{
	int a1,b1,c1,a2,b2,c2,det;
	double x,y;
	cin >> a1 >> b1 >> c1 >> a2 >> b2 >> c2;
	det = a1*b2-b1*a2;
	x = -double(c1*b2-b1*c2)/det;
	y = -double(a1*c2-c1*a2)/det;
	if(x>=0 && x<=0) x = 0;
	if(y>=0 && y<=0) y = 0;
	printf("%.2lf %.2lf\n",x,y);
}
int main()
{
	solve();
	return 0;
}
