#include <iostream>
#define FOR(i,a,b) for(i=a; i<=b; i++)
using namespace std;
int a,b,c,d;
void turn()
{
	int a2,b2,c2,d2;
	a2=a; b2=b; c2=c; d2=d;
	a=c2; b=a2; c=d2; d=b2;
}
void solve()
{
	int i,k=0;
	double maxi,t;
	scanf("%d %d %d %d",&a,&b,&c,&d);
	maxi=(double)a/(double)c+double(b)/double(d);
	FOR(i,1,3)
	{
		turn();
		t=(double)a/(double)c+double(b)/double(d);
		if(t>maxi)
		{
			maxi=t;
			k=i;
		}
	}
	printf("%d\n",k);
}
int main()
{
	solve();
	return 0;
}
