#include <cmath>
#include <cstdio>
int main()
{
	long long a,b,x,y,r;
	scanf("%lld %lld",&r,&b);
	x = ( r + 4 ) / 2;
	y = b + r;
	a = ( (long long) sqrt( x*x - 4*y ) + x ) / 2;
	printf("%lld %lld\n" , a , x - a );
	return 0;
}
