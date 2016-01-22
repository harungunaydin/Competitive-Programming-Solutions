#include <iostream>
#include <cstdio>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define MOD 1000000
using namespace std;
void solve()
{
	register long long N,i,k(0),s(1),t;
	scanf("%lld",&N);
	k = (N-1)/6 + ((N-1)%6 != 0);
	s = 3*k*k + 4*k + 1;
	t = 6*k + 1;
	if(t > N) { t--; s-=k; }
	if(t > N) { t--; s-=k+1; }
	while(t > N) { t--; s-=k; }
	printf("%lld\n",s%MOD);
}
int main()
{
	solve();
	return 0;
}
