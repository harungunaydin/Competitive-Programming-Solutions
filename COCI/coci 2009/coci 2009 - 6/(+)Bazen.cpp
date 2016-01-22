#include <iostream>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define all(x) x.begin(),x.end()
#define ALAN 31250.0
#define MAXN 
using namespace std;
void solve()
{
	double a,b,x,y;
	x = y = 0;
	cin >> a >> b;
	if(!a)
	{
		if(b <= 125)
		{
			x = ALAN/(250-b);
			y = 250 - x;
		}
		else
			x = ALAN/b;
	}
	else if(!b)
	{
		if(a < 125)
		{
			y = ALAN/(250-a);
			x = 250 - y;
		}
		else
			y = ALAN/a;
	}
	else
	{
		if(a <= 125)
			x = 250 - ALAN/b;
		else
			y = 250 - ALAN/a;
	}
	printf("%.2lf %.2lf\n",x,y);
}
int main()
{
	solve();
	return 0;
}
