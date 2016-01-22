#include <algorithm>
#include <cstdio>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define TFOR(i,a,b) for(i=a; i>=b; i--)
#define f first
#define s second
#define pb push_back
#define all(x) x.begin(),x.end()
#define MAXN 1005
#define MOD 1000000000
using namespace std;
typedef pair < int , int > pii;
int read(){ int res(0),sign(1); char c;
	while(1){ c = getchar(); if('0' <= c && c <= '9') { res = c - '0'; break; } else if(c == '-') { sign = -1; break; } }
	while(1){ c = getchar(); if('0' <= c && c <= '9') res = res*10 + c - '0'; else break; }
	return res * sign;
}
long long gcd( long long a , long long b ) { return !b ? a : gcd(b,a%b); }
long long A[MAXN] , B[MAXN];
void solve()
{
	long long res(1),t;
	int M,N,i,j,s;
	bool flag = false;
	M = read();
	FOR(i,1,M) A[i] = read();

	N = read();
	FOR(i,1,N) B[i] = read();

	FOR(i,1,M)
		FOR(j,1,N)
		{
			t = gcd(A[i],B[j]);
			A[i] /= t;
			B[j] /= t;
			res *= t;
			if(res >= MOD) flag = true;
			res %= MOD;
		}

	if(flag)
	{
		t = res; s = 0;
		while(t) { s++; t /= 10; }
		FOR(i,1,9-s) printf("0");
		printf("%lld\n" , res );
	}
	else
		printf("%lld\n" , res );



}
int main()
{
	solve();
	return 0;
}
