#include <cstdio>
#define FOR(i,a,b) for(i=a; i<=b; i++)
using namespace std;
int MOD,Q,a1,a2,b1,b2,c1,c2,f0,f1,f2,g0,g1,g2;
class matrix
{
	public:
		int A[12][12];
		matrix operator * ( matrix B )
		{
			matrix res;
			int i,j,k,t;
			FOR(i,1,6)
				FOR(j,1,6)
				{
					t = 0;
					FOR(k,1,6)
						t = ( t + A[i][k] * B.A[k][j] ) % MOD;
					res.A[i][j] = t;
				}
			return res;
		}
}M;

matrix fastexp( int n )
{
	if(n == 1) return M;

	matrix t = fastexp(n>>1);

	t = t * t;

	return (n&1) ? t * M : t;
}
void solve()
{
	matrix res;
	int i,n;
	scanf("%d %d %d",&a1,&b1,&c1);
	scanf("%d %d %d",&a2,&b2,&c2);
	scanf("%d %d %d",&f0,&f1,&f2);
	scanf("%d %d %d",&g0,&g1,&g2);
	scanf("%d %d",&MOD,&Q);
	a1 %= MOD; b1 %= MOD; c1 %= MOD;
	a2 %= MOD; b2 %= MOD; c2 %= MOD;
	f0 %= MOD; f1 %= MOD; f2 %= MOD;
	g0 %= MOD; g1 %= MOD; g2 %= MOD;
	M.A[1][1] = a1; M.A[1][2] = b1; M.A[1][6] = c1;
	M.A[4][3] = c2; M.A[4][4] = a2; M.A[4][5] = b2;
	FOR(i,1,Q)
	{
		scanf("%d",&n);
		if(n < 3) { printf("%d %d\n" , (!n?f0:n==1?f1:f2) , (!n?g0:n==1?g1:g2) ); continue; }

		res = fastexp(n-2);

		printf("%d ",(res.A[1][1] * f2 + res.A[1][2] * f1 + res.A[1][3] * f0 + res.A[1][4] * g2 + res.A[1][5] * g1 + res.A[1][6] * g0)%MOD );
		printf("%d\n",(res.A[4][1] * f2 + res.A[4][2] * f1 + res.A[4][3] * f0 + res.A[4][4] * g2 + res.A[4][5] * g1 + res.A[4][6]* g0)%MOD );
	}
}
int main()
{
	M.A[2][1] = M.A[3][2] = 1;
	M.A[5][4] = M.A[6][5] = 1;
	int T,i;
	scanf("%d",&T);
	FOR(i,1,T)
	{
		printf("Case %d:\n",i);
		solve();
	}
	return 0;
}
