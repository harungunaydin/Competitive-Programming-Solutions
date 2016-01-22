#include <iostream>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n)  FOR(i,0,n-1)
#define INF 2000000000
using namespace std;
void solve()
{
	int N,i,mini=INF,maxi=-INF,top=0,x;
	scanf("%d",&N);
	FOR(i,1,N)
	{
		scanf("%d",&x);
		if(i&1)
		{
			top+=x;
			mini = min(mini,top);
			top+=x;
		}
		else
		{
			top-=x;
			maxi = max(maxi,top);
			top-=x;
		}
	}
	printf("%d\n",max(0,mini-maxi+1));
}
int main()
{
	solve();
	return 0;
}
