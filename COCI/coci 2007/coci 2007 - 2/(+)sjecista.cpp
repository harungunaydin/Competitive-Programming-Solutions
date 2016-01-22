#include <cstdio>
main()
{
	long long N;
	scanf("%lld",&N);
	printf("%lld\n" , ( N * (N-1) * (N-2) * (N-3) ) / 24 );
}
