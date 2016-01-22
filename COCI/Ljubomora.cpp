#include<cstdio>
#include<iostream>
#include<algorithm>
#include<climits>
#define max(a,b) ( (a) > (b) ? ( a) : (b))
#define min(a,b) ( (a) < (b) ? ( a) : (b))
#define inf INT_MAX
using namespace std;
int n,m,_max,_min=inf;
int A[300005];
void bs(int bas,int son)
{
	register int t=(bas+son)/2,i,sum=0;
	if(bas==son) return ;
	for(i=1;i<=m;i++)
	{	
		sum+=A[i]/t;
		if(A[i]%t)
			sum++;
	}
	if(sum<=n)
	{
		_min=min(_min,t);
		bs(bas,t);
	}
	else
		bs(t+1,son);
}
int main()
{
	register int a,i;
	scanf("%d %d",&n,&m);
	for(i=1;i<=m;i++)
	{
		scanf("%d",&a);
		A[i]=a;
		_max=max(_max,a);
	}
	bs(1,_max);
	printf("%d\n",_min);
	return 0;
}
