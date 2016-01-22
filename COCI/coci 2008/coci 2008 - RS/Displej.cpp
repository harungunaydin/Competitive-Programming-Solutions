#include <iostream>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define MAXN 100
using namespace std;
long long A[MAXN+5];
void solve()
{
	long long N,a,b,i,res(0),sum(0);
	scanf("%lld %lld %lld",&N,&b,&a);
	FOR2(i,N)
	{
		scanf("%lld",A+i);
		sum+=A[i];
	}
	b+=a-1;
	a--; b--;
	FOR(i,a,b)
	{
		if(!(i%N) && i+N <= b) { i+=N-1; res+=sum; continue; }
		res+=A[i%N];
	}
	printf("%lld\n",res);
}
int main()
{
	solve();
	return 0;
}
