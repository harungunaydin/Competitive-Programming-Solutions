#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
int A[10000005],temp[100005];
int T,n,m,_min;
void bs(int bas,int son)
{
	register int t=(bas+son)/2,i;
	register long long k=0;
	register bool w=0;
	for(i=1;i<=t;i++)
		temp[i]=A[i];
	sort(temp + 1 , temp + t + 1);
	for(i=1;i<=t;i++)
	{
		if(k+1>=temp[i])
			k+=temp[i];
		else
			w=1;
	}
	if(k>=m && !w)
	{
		_min=min(_min,t);
		if(bas<son)
		bs(bas,t);
	}
	else
	{
		if(bas<son)
		bs(t+1,son);
	}
}
int main()
{
	register int i,j;
	scanf("%d",&T);
	while(T--)
	{
		_min=999999999;
		scanf("%d %d",&n,&m);
		for(i=1;i<=n;i++)
			scanf("%d",&A[i]);
		bs(1,n);
		if(_min==999999999) _min=-1;
		printf("%d\n",_min);
	}
	return 0;
}
