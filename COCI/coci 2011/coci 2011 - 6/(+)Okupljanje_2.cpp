#include <iostream>
using namespace std;
int main()
{
	int a,b,i;
	scanf(" %d %d",&a,&b);
	a*=b;
	for(i=0; i<5; i++)
	{
		scanf(" %d",&b);
		printf("%d",b-a);
		if(i<4) printf(" ");
	}
	printf("\n");
	return 0;
}
