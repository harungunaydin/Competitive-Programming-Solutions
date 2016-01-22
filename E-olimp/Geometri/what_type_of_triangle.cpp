#include <iostream>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define all(x) x.begin(),x.end()
using namespace std;
int solve()
{
	int a,b,c;
	cin >> a >> b >> c;
	if(a == b && b == c) return 1;
	if(a == b || b == c || a == c) return 2;
	return 3;
}
int main()
{
	cout << solve() << endl;
	return 0;
}
