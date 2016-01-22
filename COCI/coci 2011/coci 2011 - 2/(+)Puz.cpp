#include <cstdio>
main()
{
	int A,B,V;
	scanf("%d %d %d",&A,&B,&V);
	printf("%d\n" , (V-B-1) / (A-B) + 1 );
}
