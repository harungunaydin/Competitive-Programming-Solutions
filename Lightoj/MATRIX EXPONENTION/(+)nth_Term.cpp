#include <cstdio>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define MOD 10007
using namespace std;
class matris
{
	public:
		short A[4][4];
		matris() { int i,j; FOR2(i,4) FOR2(j,4) A[i][j] = 0; }
		matris operator * ( matris B )
		{
			matris res;
			int i,j,k;
			short s;
			FOR2(i,4)
				FOR2(j,4)
				{
					s = 0;
					FOR2(k,4)
						s = ( s + A[i][k] * B.A[k][j] ) % MOD;
					res.A[i][j] = s;
				}
			return res;
		}
};
matris us(matris a , int k)
{
	if(k == 1) return a;
	matris m = us( a , k / 2);
	m = m * m;
	return (k&1) ? a * m : m;
}
int main()
{
	int T,a,b,c,i,n;
	scanf("%d",&T);
	FOR(i,1,T)
	{
		printf("Case %d: ",i);
		scanf("%d %d %d %d",&n,&a,&b,&c);
		matris m;
		m.A[0][0] = a; m.A[0][2] = b; m.A[0][3] = c;
		m.A[1][0] = 1; m.A[2][1] = 1; m.A[3][3] = 1;
		if(n <= 2) { printf("0\n"); continue; }
		m = us( m , n - 2 );
		printf("%d\n" , m.A[0][3] );
	}
	return 0;
}
