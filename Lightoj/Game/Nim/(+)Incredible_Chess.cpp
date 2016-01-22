#include <cstdio>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define MAXN 101
using namespace std;
int A[MAXN];
void solve()
{
	int N,a,i,res(0);
	scanf("%d",&N);
	FOR(i,1,N) scanf("%d",A+i);
	FOR(i,1,N)
	{
		scanf("%d",&a);
		res ^= ( a - A[i] - 1 );
	}
	res ? printf("white wins\n") : printf("black wins\n");
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
