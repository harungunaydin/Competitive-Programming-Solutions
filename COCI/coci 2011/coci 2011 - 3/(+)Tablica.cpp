#include <cstdio>
#define FOR(i,a,b) for(i=a; i<=b; i++)
void solve()
{
	double a,b,c,d,maxi(-10000) , tmp;
	int i,k;
	scanf("%lf %lf %lf %lf",&a,&b,&c,&d);
	FOR(i,1,4)
	{
		tmp = a;
		a = c;
		c = d;
		d = b;
		b = tmp;
		if(a/c + b/d > maxi)
		{
			maxi = a/c + b/d;
			k = i % 4;
		}
	}

	printf("%d\n" , k );

}
int main()
{
	solve();
	return 0;
}
