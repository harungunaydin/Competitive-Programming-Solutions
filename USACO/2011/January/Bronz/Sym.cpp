#include <iostream>
using namespace std;
int main()
{
	int a,b,k=1,s=0;
	scanf("%d %d",&a,&b);
	while((a-1)&1 || (b-1)&1)
	{
		a>>=1;
		b>>=1;
		s+=k;
		k<<=2;
	}
	printf("%d\n",s);
	return 0;
}
