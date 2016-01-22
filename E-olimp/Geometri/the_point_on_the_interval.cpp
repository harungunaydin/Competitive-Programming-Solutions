#include <iostream>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define all(x) x.begin(),x.end()
using namespace std;
void solve()
{
	double a,b,c,d,e,f,g;
	cin >> a >> b >> c >> d >> e;
	c-=a; d-=b;
	f = c/(e+1); f*=e;
	g = d/(e+1); g*=e;
	printf("%.2lf %.2lf\n",a+f,b+g);
}
int main()
{
	solve();
	return 0;
}
