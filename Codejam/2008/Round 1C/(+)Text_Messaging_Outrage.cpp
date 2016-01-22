#include <iostream>
#include <algorithm>
#include <cstdio>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define TFOR(i,a,b) for(i=a; i>=b; i--)
#define MAXN 1005
using namespace std;
long long A[MAXN];
void solve()
{
	long long res(0);
	int K,L,P,i;
	scanf("%d %d %d",&P,&K,&L);

	FOR(i,1,L) scanf("%lld",A+i);

	sort(A+1,A+L+1,greater<int>());

	FOR(i,1,L) res += A[i] * ((i-1)/K + 1);

	printf("%lld\n" , res );

}
int main()
{
	int T,i;
	scanf("%d",&T);
	FOR(i,1,T)
	{
		printf("Case #%d: ",i);
		solve();
	}
	return 0;
}
