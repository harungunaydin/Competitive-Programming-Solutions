#include <iostream>
#include <cstdio>
using namespace std;
void solve()
{
	double mark=100,dolar=0;
	int i,N,x,y;
	scanf("%d",&N);
	for(i=0; i<N; i++)
	{
		scanf("%d %d",&x,&y);
		mark=max(mark,(dolar*100.0)/y);
		dolar=max(dolar,(mark*x)/100.0);
	}
	printf("%.2lf\n",mark);
}
int main()
{
	solve();
	return 0;
}
