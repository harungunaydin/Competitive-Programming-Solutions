#include <iostream>
#include <cstdio>
#include <cmath>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define all(x) x.begin(),x.end()
using namespace std;
void solve()
{
	int N,g;
	double a,b,c,d,e,f,i,res=0;
	cin >> N >> a >> b >> c >> d;
	FOR(i,3,N)
	{
		cin >> e >> f;
		res+=(c-a)*(f-d) - (d-b)*(e-c);
		c = e; d = f;
	}
	printf("%.1lf\n",abs(res/2));
}
int main()
{
	solve();
	return 0;
}
