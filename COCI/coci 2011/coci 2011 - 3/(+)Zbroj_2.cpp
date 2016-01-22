#include <iostream>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define all(x) x.begin(),x.end()
using namespace std;
int degistir(int a,int b)
{
	int k = 1;
	while(k<a)
	{
		if((a/k)%10 == b) a = (b == 5) ? a+k : a-k;
		k*=10;
	}
	return a;
}
void solve()
{
	int a,b;
	scanf("%d %d",&a,&b);
	printf("%d %d\n",degistir(a,6)+degistir(b,6),degistir(a,5) + degistir(b,5));
}
int main()
{
	solve();
	return 0;
}
