#include <iostream>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define all(x) x.begin(),x.end()
#define MAXN 100000
using namespace std;
long long Fib[MAXN+5];
long long solve()
{
	long long N,i;
	scanf("%lld",&N);
	Fib[0] = Fib[1] = 1;
	for(i=2; Fib[i-1]<=N; i++)
		Fib[i] = Fib[i-1] + Fib[i-2];
	for(i-=2; i>=1; i--)
	{
		if(N == Fib[i]) return N;
		else if(Fib[i] <= N)
			N-=Fib[i];
	}
	return N;
}
int main()
{
	printf("%lld\n",solve());
	return 0;
}
