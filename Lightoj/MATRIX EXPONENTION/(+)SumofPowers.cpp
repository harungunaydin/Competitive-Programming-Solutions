#include <cstdio>
#include <cstring>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define MAXN 55
using namespace std;
long long N;
int K,T;
class matrix
{
	public:
		unsigned int A[MAXN][MAXN];
		matrix() { }
		matrix operator * ( matrix B )
		{
			matrix res;
			unsigned int t;
			int i,j,k;
			FOR(i,1,T)
				FOR(j,1,T)
				{
					t = 0;
					FOR(k,1,T)
						t += A[i][k] * B.A[k][j];
					res.A[i][j] = t;
				}
			return res;
		}
}M;
matrix fastexp(long long n)
{
	if(n == 1) return M;

	matrix t = fastexp(n>>1);

	t = t * t;

	return n&1 ? M * t: t;
}
unsigned int DP[MAXN][MAXN];
unsigned int C(int n,int r)
{
	unsigned int &ret = DP[n][r];
	if(ret) return ret;
	if(n == r || !r || n == 1) return ret = 1;
	return ret = C(n-1,r) + C(n-1,r-1);
}
unsigned int solve()
{
	scanf("%lld %d",&N,&K);
	T = K + 2;
	int i,j;
	memset( M.A , 0 , sizeof M.A );
	M.A[1][1] = 1;
	FOR(i,2,T)
		M.A[1][i] = C(K,i-2);
	FOR(i,2,T)
		FOR(j,i,T)
			M.A[i][j] = C(T-i,j-i);

	if(N == 1) return 1;

	matrix res = fastexp(N-1);

	unsigned int s(0);

	FOR(i,1,T)
		s += res.A[1][i];

	return s;
}
int main()
{
	int T,i;
	scanf("%d",&T);
	FOR(i,1,T)
		printf("Case %d: %u\n",i , solve() );
	return 0;
}
