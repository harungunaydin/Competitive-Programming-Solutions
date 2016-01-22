#include <iostream>
#include <cstdio>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
using namespace std;
void solve()
{
	long long N,i,j,res(0);
	scanf("%lld",&N);
	FOR(i,0,N)
		FOR(j,0,i)
			res+=i+j;
	printf("%lld\n",res);
}
int main()
{
	solve();
	return 0;
}
