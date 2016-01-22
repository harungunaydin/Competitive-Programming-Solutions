#include<iostream>
#include<cstdio>
#define ii pair<int,int>
#define f first
#define s second
using namespace std;

int ST[5500005];
int n,h,w;

void update(int pos,int s, int e,int a,int b)
{
	if(b<s || a>e) return ;
	if(a<=s && e<=b)
	{
		ST[pos]++;
		return ;
	}
	if(s == e)	return;
	update(pos*2,s,(s+e)/2,a,b);
	update(pos*2+1,(s+e)/2+1,e,a,b);
}
int find(int pos,int s ,int e,int up)
{
	if(up<s || up>e) return 0;
	if(s==e)  return ST[pos]; 
	return ST[pos]+find(pos*2,s,(s+e)/2,up)+find(pos*2+1,(s+e)/2+1,e,up);
}
int main()
{
	register int a,b,i,j,t,ind,_min=999999999,sayac;
	scanf("%d %d",&n,&h);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&a);
		if(i%2)
			update(1,1,1097152,1,a);
		else
			update(1,1,1097152,h-a+1,h);
	}
	for(i=1;i<=h;i++)
	{
		t=find(1,1,1097152,i);
		if(t<_min)
		{
			_min=t;
			sayac=0;
		}
		if(t==_min)
		sayac++;
	}
	printf("%d %d\n",_min,sayac);
	return 0;
}
