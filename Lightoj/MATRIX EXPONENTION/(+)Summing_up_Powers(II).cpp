#include <cstdio>
#include <cstring>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define MAXN 31
using namespace std;
char N;
class matrix
{
	public:
		char A[MAXN][MAXN];
		matrix() { }
		matrix operator + ( matrix B )
		{
			char i,j;
			FOR(i,1,N)
				FOR(j,1,N)
					B.A[i][j] = ( A[i][j] + B.A[i][j] ) % 10;
			return B;
		}
		matrix operator * ( matrix B )
		{
			matrix res;
			char i,j,k,t;
			FOR(i,1,N)
				FOR(j,1,N)
				{
					t = 0;
					FOR(k,1,N)
						t = ( t + A[i][k] * B.A[k][j] ) % 10;
					res.A[i][j] = t;
				}
			return res;
		}
}B,C,S;
class mat
{
	public:
		matrix a1,a2,b1,b2;
		mat() {  }
		mat operator * ( mat B )
		{
			mat res;

			res.a1 = a1 * B.a1 + a2 * B.b1;
			res.a2 = a1 * B.a2 + a2 * B.b2;
			res.b1 = b1 * B.a1 + b2 * B.b1;
			res.b2 = b1 * B.a2 + b2 * B.b2;

			return res;
		}
}M;

mat fastexp(int n)
{
	if(n == 1) return M;

	mat t = fastexp(n>>1);

	return n&1 ? t * t * M : t * t;
}
matrix solve()
{
	int K;
	char i,j;

	scanf("%d %d",&N,&K);
	FOR(i,1,N)
		FOR(j,1,N)
			scanf("%d",&C.A[i][j]);

	if(K == 1) return C;

	FOR(i,1,N)
		FOR(j,1,N)
			B.A[i][j] = (i == j);

	M.a1 = B;
	M.a2 = C;
	M.b1 = S;
	M.b2 = C;

	mat tmp = fastexp(K-1);

	return tmp.a1 * C + tmp.a2 * C;

}
int main()
{
	memset( S.A , 0 , sizeof S.A );

	int T,i,j,t;
	scanf("%d",&T);
	FOR(t,1,T)
	{
		printf("Case %d:\n",t);
		matrix res = solve();
		for(i = 1; i <= N; i++,printf("\n"))
			FOR(j,1,N)
				printf("%d" , res.A[i][j] );
	}
	return 0;
}
