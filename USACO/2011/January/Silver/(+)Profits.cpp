#include <iostream>
#define FOR(i,a,b) for(i=a; i<=b; i++)
using namespace std;
void solve()
{
	int N,i,result=-1000000,top=0,x;
	scanf("%d",&N);
	FOR(i,1,N)
	{
		scanf("%d",&x);
		top+=x;
		if(top > result) result=top;
		if(top < 0) top=0;
	}
	printf("%d\n",result);
}
int main()
{
	solve();
	//system("PAUSE");
	return 0;
}
