#include <iostream>
#include <cstdio>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
using namespace std;
void solve()
{
	double a,b,res;
	int N,i;
	scanf("%lf %lf",&a,&b);
	res = a/b;
	scanf("%d",&N);
	FOR(i,1,N)
	{
		scanf("%lf %lf",&a,&b);
		res = min( res , a/b );
	}
	printf("%.2lf\n",res*1000);
}
int main()
{
	solve();
	return 0;
}
