#include <cstdio>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define MAXN 1000005
using namespace std;
inline int Min( int a , int b ) { return a < b ? a : b; }
inline int Max( int a , int b ) { return a > b ? a : b; }
int DP[MAXN];
inline void solve()
{
	register int E,F,N,a,i,j,res;
	scanf("%d %d %d",&N,&E,&F);	
	FOR(i,2,N)
	{
		res = 2000000000;
		a = (i - 1) >> 1;
		FOR(j,1,a)
			res = Min( res , Max( DP[i - 2*j] + E , DP[j] + F ) );
		DP[i] = (i&1) ? res : Min( res , DP[i>>1] + F );
	}
	printf("%d\n" , DP[N] );
}
int main()
{
	freopen("dagitim.gir","r",stdin);
	freopen("dagitim.cik","w",stdout);
	solve();
	return 0;
}
