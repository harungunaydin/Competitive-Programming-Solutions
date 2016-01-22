#include <algorithm>
#include <cstdio>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define MAXN 100001
using namespace std;
int A[MAXN];
void solve()
{
	int C,K,N,i;
	long long res(0),t(0);
	scanf("%d %d %d %d",&K,&C,&N,A+1);
	FOR(i,2,N)
		A[i] = ( (long long) K * A[i-1] + C ) % 1000007;
	
	sort(A+1,A+N+1);

	FOR(i,2,N)
		res += t += ( (long long) A[i] - A[i-1] ) * (i - 1);

	printf("%lld\n" , res );
}
int main()
{
	int T,i;
	scanf("%d",&T);
	FOR(i,1,T)
	{
		printf("Case %d: ",i);
		solve();
	}
	return 0;
}
