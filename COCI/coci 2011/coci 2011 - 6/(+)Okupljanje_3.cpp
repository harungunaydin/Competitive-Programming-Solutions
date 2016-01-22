#include <iostream>
#define FOR(i,a,b) for(i=a; i<=b; i++)
using namespace std;
void solve()
{
	int a,b,i;
	scanf("%d %d",&a,&b);
	a*=b;
	FOR(i,1,5)
	{
		scanf("%d",&b);
		printf("%d",b-a);
		if(i<5) printf(" ");
	}
	printf("\n");
}
int main()
{
	solve();
	return 0;
}
