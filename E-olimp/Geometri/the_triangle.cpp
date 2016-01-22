#include <iostream>
#include <cmath>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define all(x) x.begin(),x.end()
using namespace std;
string solve()
{
	double a,b,c,a2,b2,c2,cos1,cos2,cos3;
	cin >> a >> b >> c;
	if(a+b<=c || a+c<=b || b+c<=a) return "IMPOSSIBLE";
	a2 = a*a; b2 = b*b; c2 = c*c;
	cos1 = (b2+c2-a2)/(2*b*c);
	cos2 = (a2+c2-b2)/(2*a*c);
	cos3 = (a2+b2-c2)/(2*a*b);
	if(!cos1 || !cos2 || !cos3) return "RIGHT";
	if(cos1 < 0 || cos2 < 0 || cos3 < 0) return "OBTUSE";
	return "ACUTE";
}
int main()
{
	cout << solve() << endl;
	return 0;
}
