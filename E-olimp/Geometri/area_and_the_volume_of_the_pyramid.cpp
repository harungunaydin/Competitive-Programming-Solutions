#include <iostream>
#include <cmath>
using namespace std;
void solve()
{
	double a,b,h;
	cin >> a >> b;
	h = sqrt(b*b - (a*a/2));
	printf("%.3lf %.3lf\n",sqrt(h*h+(a*a)/4)*a*2+a*a,(a*a*h)/3);
}
int main()
{
	solve();
	return 0;
}
