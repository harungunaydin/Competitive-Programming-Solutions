#include <iostream>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define all(x) x.begin(),x.end()
#define MAXN 5
using namespace std;
void solve()
{
	int a,b,c,d,i,k,maxi(0),t;
	FOR2(i,MAXN)
	{
		cin >> a >> b >> c >> d;
		t = a + b + c + d;
		if(t > maxi)
		{
			k = i;
			maxi = t;
		}
	}
	printf("%d %d\n",k+1,maxi);
}
int main()
{
	solve();
	return 0;
}
