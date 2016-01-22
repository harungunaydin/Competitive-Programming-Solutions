#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int a,b,n,mes;
int main()
{
	register int h;
	scanf("%d %d %d",&a,&b,&n);
	mes=abs(a-b);
	while(n--)
	{
		scanf("%d",&h);
		mes=min(mes,abs(h-b));
	}
	if(mes!=abs(a-b)) mes++;
	printf("%d\n",mes);
	return 0;
}
