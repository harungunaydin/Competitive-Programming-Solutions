#include <iostream>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define f first
#define s second
using namespace std;
pair <int,int> p[1000005];
void solve()
{
	int N,i,j,k,l,mini=10000000,maxi=0,s=0,x,y;
	scanf("%d",&N);
	FOR(i,1,N)
		cin >> p[i].f >> p[i].s;
	FOR(i,1,5)
	{
		s=0;
		FOR(j,1,N)
		{
			if(p[j].f==i || p[j].s==i)
				s++;
			else s=0;
			if(s>maxi)
			{
				maxi=s;
				l=i;
			}
		}
	}
	printf("%d %d\n",maxi,l);
}
int main()
{
	solve();
	return 0;
}
