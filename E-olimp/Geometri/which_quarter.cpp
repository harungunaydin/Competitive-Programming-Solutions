#include <iostream>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define all(x) x.begin(),x.end()
using namespace std;
int solve()
{
	double a,b;
	cin >> a >> b;
	if(!a || !b) return 0;
	if(a > 0 && b > 0) return 1;
	if(a > 0) return 4;
	if(a < 0 && b < 0) return 3;
	return 2;
}
int main()
{
	cout << solve() << endl;
	return 0;
}
