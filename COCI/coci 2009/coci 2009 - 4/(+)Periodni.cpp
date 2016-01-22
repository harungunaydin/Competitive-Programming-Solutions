#include <iostream>
#include <cstdio>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define TFOR(i,a,b) for(i=a; i>=b; i--)
#define INF 20000000000000000LL
#define MAXN 1000
#define MOD 1000000007LL
using namespace std;
class Histogram
{
	public:
		long long A[MAXN+5];
		Histogram() { for(long long i = 0; i<MAXN+4; i++) A[i] = 0; }
};
inline long long gcd(long long a,long long b) { return !b ? a : gcd(b,a%b); }
long long K,N;
long long A[MAXN+5],B[MAXN+5],C[MAXN+5],H[MAXN+5];
long long PERM[MAXN+5][MAXN+5];
void COMB(long long n)
{
	long long a,i,j,g,res(0),t;
	FOR(i,0,K)
	{
		t = i;
		B[i] = n - i + 1;
		FOR(j,1,i)
		{
			g = gcd( t , B[j] );
			B[j]/=g;
			t/=g;
			if(t == 1) break;
		}
		C[i] = 1;
		FOR(j,1,i) C[i] = (C[i] * B[j]) % MOD;
	}
}
Histogram f(long long a,long long b,long long alt)
{
	Histogram cur;
	if(a > b) { cur.A[0] = 1; return cur; }
	long long i,j,minh(INF),minik;
	bool flag = true;
	FOR(i,a,b)
	{
		if(H[i] < minh) { minh = H[i]; minik = i; }
		if(H[i] != H[b]) flag = false;
	}
	long long m = minh - alt, n = b - a + 1;
	if(flag)
	{
		COMB(m);
		FOR(i,0,K)
			cur.A[i] = ( (PERM[n][i] % MOD) * (C[i] % MOD) ) % MOD;
	}
	else if(minh > alt)
	{
		Histogram tmp = f(a,b,minh);
		COMB(m);
		FOR(i,0,K)
			for(j = 0; j <= i && n >= j; j++)
				cur.A[i] = ( cur.A[i] + ( ( (tmp.A[j] % MOD ) * ( PERM[n-j][i-j] % MOD ) % MOD ) * ( C[i-j] % MOD )) ) % MOD;
	}
	else
	{
		Histogram sol = f(a,minik-1,alt) , sag = f(minik+1,b,alt);
		FOR(i,0,K)
			FOR(j,0,i)
				cur.A[i] = ( cur.A[i] + ( sol.A[j] % MOD ) * ( sag.A[i-j] % MOD ) ) % MOD;
	}
	return cur;
}
int main()
{
	long long i,j;
	scanf("%lld %lld",&N,&K);
	FOR(i,1,N) scanf("%lld",H+i);
	FOR(i,1,N)
	{
		PERM[i][0] = 1ll;
		FOR(j,1,i)
			PERM[i][j] = ( PERM[i][j-1] % MOD * (i-j+1) % MOD ) % MOD;
	}
	printf("%lld\n", f(1,N,0).A[K] % MOD);
	return 0;
}
