#include <algorithm>
#include <cstdio>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define TFOR(i,a,b) for(i=a; i>=b; i--)
#define all(x) x.begin(),x.end()
using namespace std;
void solve()
{
	int K,M,N,a,b,i,res(0);
	scanf("%d %d %d",&M,&N,&K);
	FOR(i,0,K)
	{
		a = M - i;
		b = N - ( K - i );
		res = max( res , min(a/2,b) );
	}
	printf("%d\n" , res );
}
int main()
{
	solve();
	return 0;
}
