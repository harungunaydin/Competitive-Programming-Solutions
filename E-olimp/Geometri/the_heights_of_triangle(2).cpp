#include <iostream>
#include <cmath>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define all(x) x.begin(),x.end()
using namespace std;
void solve()
{
	double a,b,c,u,s;
	cin >> a >> b >> c;
	u = (a+b+c)/2;
	s = sqrt(u*(u-a)*(u-b)*(u-c))*2;
	printf("%.2lf %.2lf %.2lf\n",s/a,s/b,s/c);
}
int main()
{
	solve();
	return 0;
}
