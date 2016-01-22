#include <iostream>
#define FOR(i,a,b) for(i=a; i<=b; i++)
using namespace std;
int C,L,N;
int main()
{
	int i,x,y;
	scanf("%d %d %d",&L,&C,&N);
	FOR(i,1,C)
	{
		scanf("%d %d",&x,&y);
		printf("%d\n",abs(N - y) + x);
	}
	return 0;
}
