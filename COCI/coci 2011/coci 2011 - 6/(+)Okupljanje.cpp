#include <cstdio>
#define FOR(i,a,b) for(i=a; i<=b; i++)
main()
{
	int a,b,i;
	scanf("%d %d",&a,&b);
	a *= b;
	FOR(i,1,5)
	{
		scanf("%d",&b);
		printf("%d " , b - a );
	}
}
