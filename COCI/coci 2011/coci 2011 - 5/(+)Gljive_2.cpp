#include <iostream>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define all(x) x.begin(),x.end()
#define MAXN 
using namespace std;
void solve()
{
	int a,i,t(0);
	FOR2(i,10)
	{
		scanf("%d",&a);
		if(t+a <= 100) t+=a;
		else
		{
			if(t+a-100 <= 100-t) t+=a;
			break;
		}
	}
	printf("%d\n",t);
}
int main()
{
	solve();
	return 0;
}
