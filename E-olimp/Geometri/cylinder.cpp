#include <iostream>
#include <cmath>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define all(x) x.begin(),x.end()
using namespace std;
const double PI = acos(-1);
void solve()
{
	double a,b,r,res;
	while(1)
	{
		cin >> a >> b;
		if(!a) return;
		if(a > b) swap(a,b);
		r = a / (2*PI);
		res = PI*r*r*(b-2*r);
		r = b / (2*PI+2);
		if(2*r > a) r = a/2;
		printf("%.3lf\n",max(res,r*r*PI*a));
	}
}
int main()
{
	solve();
	return 0;
}
