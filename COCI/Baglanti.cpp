#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#define f first
#define s second
using namespace std;
int n,m,e,ata[105],k,sayi=1,_min=999999,kalk[10],kk;
bool H[1000000];
pair < int , pair < int , int  > > A[1000005];
int atabul(int t)
{
	if(ata[t]==t) return t;
	return atabul(ata[t]);
}
int main()
{
	int a,b,c,i,j;
	cin >> n >> k;
	for(i=0;i<k;i++)
	{
		sayi*=2;
		cin >> a;
		kalk[++kk]=a;
	}
	cin >> e;
	for(i=1;i<=e;i++)
	{
		scanf("%d %d %d",&a,&b,&c);
		A[i].f=c;
		A[i].s.f=a;
		A[i].s.s=b;
	}
	sayi++;
	sort(A+1,A+e+1);
	while(sayi-->0)
	{

		for(i=1;i<=kk;i++)
			H[kalk[i]] = ( (sayi >> (i-1) ) & 1);

		int cost=0;
		for(i=1;i<=n;i++) ata[i]=i;
		for(i=1;i<=e;i++)
		{
			int x=atabul(A[i].s.f),y=atabul(A[i].s.s);
			if(!H[A[i].s.f] && !H[A[i].s.s] && x!=y)
			{
				cost+=A[i].f;
				ata[x]=ata[y];
			}
		}
		_min=min(_min,cost);
		memset(H, 0 , sizeof(H));
	}
	cout << _min << endl;
	return 0;
}
