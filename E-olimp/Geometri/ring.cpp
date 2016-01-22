#include <iostream>
#include <cmath>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define all(x) x.begin(),x.end()
using namespace std;
void solve()
{
	double a,b;
	cin >> a >> b;
	printf("%.2lf\n",sqrt(b*b-a/acos(-1)));
}
int main()
{
	solve();
	return 0;
}
