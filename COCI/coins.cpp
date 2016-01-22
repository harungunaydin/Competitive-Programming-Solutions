#include<iostream>
#include<cstdio>
using namespace std;
bool winner[1000000];
int A[10005],k,l,n,_max,K,L,_1;
int main()
{
	register int i,j;
	scanf("%d %d %d",&k,&l,&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&A[i]);
		_max=max(_max,A[i]);
	}
	for(i=1;i<=_max;i++)
	{
		_1=winner[i-1];
		if(i-k>=0) K=winner[i-k]; else K=1;
		if(i-l>=0) L=winner[i-l]; else L=1;
		if(!(K && L && _1)) winner[i]=1;
	}
	for(i=1;i<=n;++i)
	{
		if(winner[A[i]]) printf("A");
		else printf("B");
	}
	return 0;
}
