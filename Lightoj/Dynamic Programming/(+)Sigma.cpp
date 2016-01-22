#include <cmath>
#include <cstdio>
#define FOR(i,a,b) for(i=a; i<=b; i++)
main()
{
	long long n,res;
	int T,i;
	scanf("%d",&T);
	FOR(i,1,T)
	{
		scanf("%lld" , &n );
		res = n;
		while(n)
		{
			res -= ( (int) sqrt(n) + 1 ) / 2;
			n /= 2;
		}
		printf("Case %d: %lld\n" , i , res );
		
	}
}
