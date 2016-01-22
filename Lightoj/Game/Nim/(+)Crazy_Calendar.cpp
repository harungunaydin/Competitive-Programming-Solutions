#include <iostream>
#include <cstdio>
#define FOR(i,a,b) for(i=a; i<=b; i++)
using namespace std;
int main()
{
	int M,N,T,a,i,j,res;
	short t;
	scanf("%d",&T);
	FOR(t,1,T)
	{
		res = 0;
		scanf("%d %d",&M,&N);
		FOR(i,1,M)
			FOR(j,1,N)
			{
				scanf("%d",&a);
				if( (M + N - i - j)&1 )
					res ^= a;
			}
		printf("Case %hd: ",t);
		res ? printf("win\n") : printf("lose\n");
	}
	return 0;
}
