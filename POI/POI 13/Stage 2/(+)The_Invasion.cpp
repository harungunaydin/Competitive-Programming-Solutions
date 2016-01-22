#include <algorithm>
#include <cstdio>
#include <list>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define TFOR(i,a,b) for(i=a; i>=b; i--)
#define F(x) ( ((x) == N) ? (1) : ((x)+1) )
#define G(x) ( ((x) == 1) ? (N) : ((x)-1) )
#define MAXN 605
#define MAXM 10005
using namespace std;
class point
{
	public:
		int x,y;
		point() { x = y = 0; }
		void read() { scanf("%d %d",&x,&y); }
}A[MAXN] , P[MAXM] , TMP[MAXN] ;
int M,N;
int B[MAXM];
int T[MAXN][MAXN];
long long ccw( point a , point b , point c )
{
	return (long long)(b.x - a.x) * (long long)(c.y - a.y) - (long long)(b.y - a.y) * (long long)(c.x - a.x);
}
int BS(int bas,int son,int k)
{
	if(bas == son) return bas;
	if(bas + 1 == son) return ( ccw( TMP[1] , TMP[bas] , P[k] ) > 0 ) ? bas : son;
	int orta = ( bas + son ) >> 1;

	if(ccw( TMP[1] , TMP[orta] , P[k] ) > 0) return BS(bas,orta,k);
	
	return BS(orta+1,son,k);

}
int K[MAXN];
void Initialize()
{
	int i,j,k,s,t;

	FOR(i,1,N)
	{
		s = 0;
		FOR(j,i,N)
			TMP[++s] = A[j];
		FOR(j,1,i-1)
			TMP[++s] = A[j];
		FOR(j,1,N) K[j] = 0;

		FOR(j,1,M)
		{
			t = BS(3,N,j);

			t += i - 1;

			if(t > N) t -= N;

			K[t] += B[j];
		}
		
		FOR(j,i+1,N)
			T[i][j] = T[i][j-1] + K[j];

		FOR(j,1,i-1)
			T[i][j] = T[i][G(j)] + K[j];

	}

}

void solve()
{
	register long long res , s(0);
	res = -2000000000000ll;
	register int i,j,k;
	scanf("%d",&N);
	FOR(i,1,N)
		A[i].read();
	
	scanf("%d",&M);
	FOR(i,1,M)
	{
		P[i].read();
		scanf("%d" , B+i );
		s += B[i];
	}

	Initialize();

	FOR(i,1,N)
		FOR(j,i+1,N)
			FOR(k,j+1,N)
				res = max( res , s - T[i][j] - T[j][k] - T[k][i] );

	printf("%lld\n" , res );
				

}
int main()
{
	solve();
	return 0;
}
