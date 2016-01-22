#include <cstdio>
#define FOR(i,a,b) for(i=a; i<=b; i++)
int A[25];
main()
{
	int N,a,i,s;
	scanf("%d",&N);
	FOR(i,1,N)
	{
		scanf("%d",&a);
		for(s = 0; a; a >>= 1,s++)
			A[s] += (a&1);
	}
	long long res(0);
	FOR(i,0,20)
		res += (long long) (1 << i) * (long long) (A[i]) * (long long) ( N - A[i] );

	printf("%lld\n" , res );

}
