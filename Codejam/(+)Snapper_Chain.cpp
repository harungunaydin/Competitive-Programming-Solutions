#include <cstdio>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define MAXN
using namespace std;
void solve()
{
	int K,N;
	scanf("%d %d",&N,&K);
	if( ( K % (1<<N) )  >= (1 << N) - 1)
		printf("ON\n");
	else
		printf("OFF\n");
}
int main()
{
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
	int T,i;
	scanf("%d",&T);
	FOR(i,1,T)
	{
		printf("Case #%d: ",i);
		solve();
	}
	return 0;
}
