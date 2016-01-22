#include <iostream>
#include <cmath>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define all(x) x.begin(),x.end()
using namespace std;
void solve()
{
	double x1,x2,y1,y2;
	cin >> x1 >> y1 >> x2 >> y2;
	printf("%.6lf\n",sqrt((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1)));
}
int main()
{
	solve();
	return 0;
}
