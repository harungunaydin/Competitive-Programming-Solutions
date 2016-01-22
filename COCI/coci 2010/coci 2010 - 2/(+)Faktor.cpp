#include <iostream>
#include <cmath>
#include <cstdio>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
using namespace std;
void solve()
{
	int a,b;
	cin >> a >> b;
	printf("%d\n",a*(b-1) + 1);
}
int main()
{
	solve();
	return 0;
}
