#include <cstdio>
#define FOR(i,a,b) for(i=a; i<=b; i++)
using namespace std;
int main()
{
	int N,T,a,b,i,res,t;
	scanf("%d",&T);
	FOR(t,1,T)
	{
		scanf("%d",&N);
		res = 0;
		FOR(i,1,N)
		{
			scanf("%d %d",&a,&b);
			res ^= ( b - a - 1);
		}
		printf("Case %d: ",t);
		res ? printf("Alice\n") : printf("Bob\n");
	}
	return 0;
}
