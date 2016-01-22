#include <algorithm>
#include <cstdio>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define TFOR(i,a,b) for(i=a; i>=b; i--)
#define BASE1 1000009ll
#define BASE2 10000000009llu
#define MOD 100000007ll
#define MAXN 305
using namespace std;
long long T[MAXN] , T2[MAXN] , us_base1[MAXN];
long long A[MAXN][MAXN] , H[MAXN][MAXN] , H2[MAXN][MAXN];
long long unsigned C[MAXN] , C2[MAXN] , us_base2[MAXN];
int M,N;
void solve()
{
	int i,j,y1,y2;
	char c;
	scanf("%d %d",&M,&N);
	FOR(i,1,M)
		FOR(j,1,N)
		{
			scanf(" %c" , &c );
			A[i][j] = c - '0' + 1;
			H[i][j] = ( H[i][j-1] * BASE1 + A[i][j] ) % MOD;
		}

	TFOR(i,M,1)
		TFOR(j,N,1)
			H2[i][j] = ( H2[i][j+1] * BASE1 + A[i][j] ) % MOD;

	us_base1[0] = 1ll;
	us_base2[0] = 1llu;

	FOR(i,1,300)
	{
		us_base1[i] = ( us_base1[i-1] * BASE1 ) % MOD;
		us_base2[i] = us_base2[i-1] * BASE2;
	}

	long long unsigned a , b;
	int k,res(-1);

	FOR(y1,1,N)
		FOR(y2,y1+1,N)
		{
			k = y2 - y1 + 1;

			if( res >= k ) continue;

			FOR(i,1,M)
			{
				T[i] = ( H[i][y2] - H[i][y1-1] * us_base1[k] + MOD * MOD ) % MOD;
				T2[i] = ( H2[i][y1] - H2[i][y2+1] * us_base1[k] + MOD * MOD ) % MOD;
			}

			FOR(i,1,M)
				C[i] = C[i-1] * BASE2 + (long long unsigned) T[i];

			TFOR(i,M,1)
				C2[i] = C2[i+1] * BASE2 + (long long unsigned) T2[i];


			FOR(i,1,M)
			{
				a = C[i+k-1] - C[i-1] * us_base2[k];
				b = C2[i] - C2[i+k] * us_base2[k];
				if(a == b)
					res = k;
			}

		}

	printf("%d\n" , res );

}
int main()
{
	solve();
	return 0;
}
