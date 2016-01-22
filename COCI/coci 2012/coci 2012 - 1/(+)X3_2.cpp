#include <iostream>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define all(x) x.begin(),x.end()
using namespace std;
long long A[25][2];
void solve()
{
	long long res(0);
	long long N,a,i,j;
	scanf("%lld",&N);
	FOR2(i,N)
	{
		scanf("%lld",&a);
		FOR2(j,21)
		{
			A[j][(a&1)]++;
			a>>=1;
		}
	}
	FOR2(j,21)
		res+=A[j][0]*A[j][1]*(1<<j);
	printf("%lld\n",res);
}
int main()
{
	solve();
	return 0;
}
