#include <iostream>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define all(x) x.begin(),x.end()
#define MAXN 
using namespace std;
void solve()
{
	int N,i,k(2),res(2);
	scanf("%d",&N);
	FOR(i,2,N)
	{
		res+=k;
		k+=(i&1);
	}
	printf("%d\n",res);
}
int main()
{
	solve();
	return 0;
}
