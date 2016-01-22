#include <iostream>
#include <cmath>
#define FOR(i,a,b) for(i=a; i<=b; i++)
using namespace std;
void solve()
{
	int B,L,R,W,a,i,t;
	scanf("%d %d",&R,&B);
	t=B+R;
	a=(int)sqrt(t);
	R/=2;
	FOR(i,1,a)
		if(!(t%i))
		{
			L=i;
			W=t/i;
			if(L+W-2==R)
			{
				printf("%d %d\n",max(L,W),min(L,W));
				exit(0);
			}
		}
}
int main()
{
	solve();
	return 0;
}
