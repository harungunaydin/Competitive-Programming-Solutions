#include <iostream>
#include <cstdio>
#include <cmath>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define all(x) x.begin(),x.end()
using namespace std;
void solve()
{
	double a,b,c;
	while(scanf("%lf %lf %lf",&a,&b,&c) != EOF)
	{
	  if(!a) return;
	  cout << ((a*a + b*b == c*c || a*a + c*c == b*b || b*b + c*c == a*a) ? "right" : "wrong") << endl;
	}
}
int main()
{
	solve();
	return 0;
}
