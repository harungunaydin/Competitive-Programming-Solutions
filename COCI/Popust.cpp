#include<iostream>
#include<cstdio>
#include<algorithm>
#define ii pair<long long ,long long>
#define f first
#define s second
#define mp make_pair
using namespace std;
ii A[100005],a=mp(1555555555,0);
long long  n,_min=1555555555,top,w,m;
bool cmp(ii x,ii y){ return x.s<y.s; }
int main()
{
	register int i,j,k;
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld %lld",&A[i].f,&A[i].s);
		_min=min(_min,A[i].f);
		if(a.f-a.s>A[i].f-A[i].s)
		{
			a=A[i];
		}
	}
	sort(A+1,A+n+1,cmp);
	printf("%lld\n",_min);
	for(i=2;i<=n;i++)
	{
		w=0;
		top=0;
		top+=a.f;
		m=i-1;
		for(j=1;m;j++)
		{
			if(A[j]==a && !w)  w=1;
			else
			{
				top+=A[j].s;
				m--;
			}
		}
		printf("%lld\n",top);
	}
	return 0;
}
