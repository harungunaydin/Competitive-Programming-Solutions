#include <algorithm>
#include <cstdio>
#include <map>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define TFOR(i,a,b) for(i=a; i>=b; i--)
#define MAXK 3000000000000000000ll
#define all(x) x.begin(),x.end()
using namespace std;
map < long long , int > DP;
long long Fib[100];
int dp(long long x)
{
	if(x > MAXK) return 0;

	if(DP.find(x) != DP.end()) return DP[x];

	if(!x) return 0;

	int i,k(91);

	while(x < Fib[k]) k--;
	
	return DP[x] = min( dp(x-Fib[k]) , dp(Fib[k+1] - x ) ) + 1;


}
void solve()
{
	long long a;
	int N,i;
	Fib[0] = Fib[1] = 1;
	FOR(i,1,91)
		Fib[i] = Fib[i-1] + Fib[i-2];

	scanf("%d",&N);
	while(N--)
	{
		scanf("%lld",&a);
		printf("%d\n" , dp(a) );
	}
}
int main()
{
	freopen("fib.gir","r",stdin);
	freopen("fib.cik","w",stdout);
	solve();
	return 0;
}
