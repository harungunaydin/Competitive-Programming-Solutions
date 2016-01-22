#include <cstdio>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define MAXN 25
using namespace std;
inline long double Max( long double a , long double b ) { return a > b ? a : b; }
long double DP[1<<20];
long double A[MAXN][MAXN];
int M,N;
bool DP2[1<<20];
long double dp(int mask)
{
	if(DP2[mask]) return DP[mask];

	if(mask == M)
	{
		DP2[mask] = true;
		return DP[mask] = 1.0;
	}

	int a(mask) , i , x(0);
	
	while(a) { a -= a&-a; x++; } // SU AN KACINCI KISIDEYIZ

	long double res(0);

	FOR2(i,N)
		if( !( mask&(1<<i) ) )
			res = Max( res , dp(mask|(1<<i)) * A[x][i] );

	DP2[mask] = true;
	return DP[mask] = res;
}
void solve()
{
	int i,j;
	scanf("%d",&N);
	FOR2(i,N)
		FOR2(j,N)
		{
			scanf("%Lf" , A[i] + j );
			A[i][j] /= 100.0;
		}

	M = (1<<N) - 1;

	long double res(0);

	FOR2(i,N)
		res = Max( res , dp(1 << i) * A[0][i] );

	printf("%.12Lf\n" , res * 100 );

}
int main()
{
	solve();
	return 0;
}
