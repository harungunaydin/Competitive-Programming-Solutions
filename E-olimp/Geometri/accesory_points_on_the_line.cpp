#include <iostream>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define all(x) x.begin(),x.end()
using namespace std;
string solve()
{
	double a,b,c,x,y;
	cin >> x >> y >> a >> b >> c;
	return a*x + b*y + c == 0 ? "YES" : "NO";
}
int main()
{
	cout << solve() << endl;
	return 0;
}
