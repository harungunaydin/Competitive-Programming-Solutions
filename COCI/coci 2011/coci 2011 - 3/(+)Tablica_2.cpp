#include <iostream>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define all(x) x.begin(),x.end()
using namespace std;
double a,b,c,d;
void cevir()
{
	double t = c;
	c = d; d = b;
	b = a; a = t;
}
void solve()
{
	int i,maxx;
	double maxi(-10000),t;
	scanf("%lf %lf %lf %lf",&a,&b,&c,&d);
	FOR2(i,4)
	{
		t = a/c + b/d;
		if(t > maxi)
		{
			maxi = t;
			maxx = i;
		}
		cevir();
	}
	printf("%d\n",maxx);
}
int main()
{
	solve();
	return 0;
}
