#include <iostream>
#include <cstdio>
#define FOR(i,a,b) for(i=a; i<=b; i++)
using namespace std;
short MOD;
class matrix
{
	public:
		short a,b,c,d;
		matrix operator * ( matrix t )
		{
			matrix res;
			res.a = ( a * t.a + b * t.c ) % MOD;
			res.b = ( a * t.b + b * t.d ) % MOD;
			res.c = ( c * t.a + d * t.c ) % MOD;
			res.d = ( c * t.b + d * t.d ) % MOD;
			return res;
		}
}m;
matrix us(int x)
{
	if(x == 1) return m;
	matrix c = us(x>>1);
	c = c * c;
	return (x&1) ? c * m : c;
}
short pow[5] = {0,10,100,1000,10000};
void solve()
{
	int n;
	short a,b,k;

	scanf("%hd %hd %d %hd",&a,&b,&n,&k);
	
	MOD = pow[k];

	m.a = m.b = m.c = 1; m.d = 0;

	matrix res = us(n-1);

	printf("%hd\n" , ( res.a * b + res.b * a ) % MOD );
}
int main()
{
	short T,i;
	scanf("%hd",&T);
	FOR(i,1,T)
	{
		printf("Case %hd: ",i);
		solve();
	}
	return 0;
}
