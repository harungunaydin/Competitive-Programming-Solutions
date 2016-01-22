#include <cstdio>
#define FOR(i,a,b) for(i=a; i<=b; i++)
using namespace std;
void solve()
{
	int M,N,a,i,j,res(0),s;
	scanf("%d %d",&M,&N);
	FOR(i,1,M)
	{
		s = 0;
		FOR(j,1,N)
			{
			scanf("%d",&a);
			s += a;
		}
		res ^= s;
	}
	res ? printf("Alice\n") : printf("Bob\n");
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
