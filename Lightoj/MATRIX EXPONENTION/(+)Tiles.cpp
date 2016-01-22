#include <cstdio>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define MOD 10007
using namespace std;
class matrix
{
	public:
		int A[4][4];
		matrix() { }
		matrix operator * ( matrix B )
		{
			matrix res;
			int i,j,k,t;
			FOR(i,0,3)
				FOR(j,0,3)
				{
					t = 0;
					FOR(k,0,3)
						t = ( t + A[i][k] * B.A[k][j] ) % MOD;
					res.A[i][j] = t;
				}
			return res;
		}
}M,res;
matrix fastexp(int n)
{
	if(n == 1) return M;
	
	matrix t = fastexp(n>>1);

	return n&1 ? M * t * t: t * t;
}
int main()
{
	M.A[0][0] = M.A[0][1] = M.A[0][2] = M.A[0][3] = 1;
	M.A[1][0] = M.A[2][1] = M.A[2][3] = M.A[3][1] = M.A[3][2] = 1;
	int T,i,n;
	scanf("%d",&T);
	FOR(i,1,T)
	{
		printf("Case %d: ",i);
		scanf("%d",&n);
		if(n == 1) { printf("1\n"); continue; }
		res = fastexp(n-1);
		printf("%d\n" , ( res.A[0][0] + res.A[0][1] ) % MOD );
	}
	return 0;
}
