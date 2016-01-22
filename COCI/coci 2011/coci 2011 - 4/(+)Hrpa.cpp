#include <algorithm>
#include <cstdio>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define TFOR(i,a,b) for(i=a; i>=b; i--)
#define all(x) x.begin(),x.end()
#define K 1000000000000000ll
#define MAXN 100
using namespace std;
long long Fib[MAXN];
void solve()
{
	int i;
	Fib[0] = Fib[1] = 1;
	FOR(i,2,90)
	{
		Fib[i] = Fib[i-1] + Fib[i-2];
		if( Fib[i] < 0 || Fib[i] > K) break;
	}

	long long N;

	scanf("%lld",&N);

	for(i--; i >= 0; i--)
		if(N > Fib[i])
			N -= Fib[i];
		else if(N == Fib[i])
		{
			printf("%lld\n" , N );
			break;
		}

}
int main()
{
	solve();
	return 0;
}
