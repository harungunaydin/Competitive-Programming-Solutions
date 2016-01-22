#include<iostream>
#include<cstdio>
#define inf 0xF7777777
#define min(a,b) ((a)< (b) ? (a) : (b))
double _min=inf,a,b;
int n;
int main()
{
	scanf("%lf %lf %d",&a,&b,&n);
	_min=min(_min,(1000/b)*a);
	while(n--)
	{
		scanf("%lf %lf",&a,&b);
		_min=min(_min,(1000/b)*a);
	}
	printf("%.2lf\n",_min);
	return 0;
}
