#include <iostream>
using namespace std;
main()
{
	int a,b,c;
	scanf("%d %d %d",&a,&b,&c);
	printf("%d\n",max(b-a,c-b)-1);
}
