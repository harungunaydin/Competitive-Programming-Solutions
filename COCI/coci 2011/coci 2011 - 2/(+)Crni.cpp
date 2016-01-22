#include <algorithm>
#include <cstdio>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define TFOR(i,a,b) for(i=a; i>=b; i--)
#define f first
#define s second
#define H(x1,y1,x2,y2,k) ( T[x2][y2][k] - T[x2][y1-1][k] - T[x1-1][y2][k] + T[x1-1][y1-1][k] )
#define all(x) x.begin(),x.end()
#define MOD 10007ll
#define MAXN 1005
using namespace std;
typedef pair < int , int > pii;
pii sta[MAXN];
int N;
long long TMP[MAXN][MAXN];
long long T[MAXN][MAXN][4];
int H[MAXN][MAXN];
char A[MAXN][MAXN];

void dondur_90()
{
	int i,j,s(0);
	FOR(i,1,N)
		FOR(j,1,N)
			TMP[i][j] = A[i][j];

	FOR(j,1,N)
		TFOR(i,N,1)
		{
			s++;
			A[(s+N-1)/N][(s+N-1)%N+1] = TMP[i][j];
		}
			
}
void dondur_270(int k)
{
	int i,j,s(0);
	FOR(i,1,N)
		FOR(j,1,N)
			TMP[i][j] = T[i][j][k];

	TFOR(j,N,1)
		FOR(i,1,N)
		{
			s++;
			T[(s+N-1)/N][(s+N-1)%N+1][k] = TMP[i][j];
		}
}
void Initialize(int k)
{
	int bas,i,j,sum(0),x;

	FOR(i,1,N)
	{
		FOR(j,1,N)
				H[i][j] = (A[i][j] == 'C') ? H[i-1][j] + 1 : 0;

		bas = 0;
		sum = H[i][1];
		sta[++bas] = make_pair(1,H[i][1]);
		
		T[i][1][k] = H[i][1];

		FOR(j,2,N) // HISTOGRAM
		{
			x = j;

			while( bas && H[i][j] <= sta[bas].s )
			{
				sum -= (x - sta[bas].f) * sta[bas].s;
				x = sta[bas--].f;
			}

			sta[++bas] = make_pair( x , H[i][j] );

			T[i][j][k] = sum += (j - x + 1) * sta[bas].s;

		}

		FOR(j,1,N)
			if(A[i][j] == 'C')
				T[i][j][k]--;
	}

	dondur_90();

	FOR2(i,k) dondur_270(k);
}
void solve()
{
	int i,j,k;
	scanf("%d",&N);
	FOR(i,1,N)
		scanf("%s" , A[i] + 1 );

	FOR2(i,4) Initialize(i); // DONDUR VE INITIALIZE ET
	
	FOR(i,1,N)
		FOR(j,1,N)
			FOR2(k,4)
				T[i][j][k] += T[i][j-1][k] + T[i-1][j][k] - T[i-1][j-1][k];

	long long res(0);

	FOR(i,1,N)
	{
		res = ( res + H(1,i,N,i,0) * H(1,i+1,N,N,2) ) % MOD; // SUTUN
		res = ( res + H(i,1,i,N,0) * H(i+1,1,N,N,1) ) % MOD; // SATIR
	}

	FOR(i,1,N)
		FOR(j,1,N)
		{	
			res = ( res - H(i,j,i,j,0) * H(i+1,j+1,N,N,2) + MOD * MOD ) % MOD;
			res = ( res - H(i,j,i,j,3) * H(i+1,1,N,j-1,1) + MOD * MOD ) % MOD;
		}

	printf("%lld\n" , res );

}
int main()
{
	solve();
	return 0;
}
