#include <iostream>
#define FOR(i,a,b) for(i=a; i<=b; i++)
using namespace std;
int N,s;
int fark[1005];
void solve()
{
	int px,x,i,temp=true;
	scanf("%d",&N);
	FOR(i,1,N) scanf("%d",&fark[i]);
	FOR(i,1,N)
	{
		scanf("%d",&x);
		fark[i]-=x;
	}
	while(temp!=s)
	{
		temp=s;
		px=(fark[1]>0)? 1 : (fark[1]<0)? -1 : 0;
		if(fark[1]<0) fark[1]++;
		else if(fark[1]>0) fark[1]--;
		FOR(i,2,N)
		{
			x=(fark[i]>0)? 1 : (fark[i]<0)? -1 : 0;
			if(!x)
			{
				if(px) s++;
				px=x;
				continue;
			}
			if(x!=px && px) s++;
			if(fark[i]<0) fark[i]++;
			else if(fark[i]>0) fark[i]--;
			px=x;
		}
		if(x) s++;
	}
	printf("%d\n",s);
}
int main()
{
	solve();
	return 0;
}
