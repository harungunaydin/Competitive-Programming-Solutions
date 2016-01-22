#include <cstdio>
int gcd(int a,int b) { return !b ? a : gcd(b,a%b); }
int main()
{
	int N,a,b,g;
	scanf("%d",&N); N--;
	scanf("%d",&a);
	while(N--)
	{
		scanf("%d",&b);
		g = gcd(a,b);
		printf("%d/%d\n" , a / g , b / g );
	}
	return 0;
}
