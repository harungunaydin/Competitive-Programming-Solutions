#include <algorithm>
#include <cstdio>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define TFOR(i,a,b) for(i=a; i>=b; i--)
#define f first
#define s second
#define pb push_back
#define all(x) x.begin(),x.end()
#define MAXN 1000005
using namespace std;
typedef pair < int , int > pii;
typedef pair < long long , long long > pll;
int read(){ int res(0),sign(1); char c;
	while(1){ c = getchar(); if('0' <= c && c <= '9') { res = c - '0'; break; } else if(c == '-') { sign = -1; break; } }
	while(1){ c = getchar(); if('0' <= c && c <= '9') res = res*10 + c - '0'; else break; }
	return res * sign;
}
pll sta[MAXN];
long long A[MAXN] , DP[MAXN] , T[MAXN];
int K,N;
double inter_x( pll l1 , pll l2 ) { return (double) (l1.s - l2.s) / (l2.f - l1.f); };
int BS(int bas,int son,long long x)
{
	int orta = ( bas + son ) >> 1;
	if(orta == K - 1) return orta;
	if(!orta) return ( inter_x(sta[0],sta[1]) < x ) ? 0 : 1;

	double x1 = inter_x(sta[orta-1],sta[orta]);
	double x2 = inter_x(sta[orta],sta[orta+1]);

	if(x2 <= x && x <= x1) return orta;

	return (x < x2) ? BS(orta+1,son,x) : BS(bas,orta-1,x);
}
void add(pll l)
{
	while( K > 1 && inter_x(l,sta[K-2]) > inter_x(sta[K-1],sta[K-2]) ) K--;
	sta[K++] = l;
}
void solve()
{
	N = read();
	long long a = read() , b = read() , c = read() , x;
	int i,k,t;
	FOR(i,1,N)
		T[i] = T[i-1] + ( A[i] = read() );

	DP[N+1] = a * T[N] * T[N];

	TFOR(i,N,1)
	{
		add( make_pair( T[i] , DP[i+1] ) );

		k = T[i-1];
		x = b - 2*a*k;
		t = BS(0,K-1,x);

		DP[i] = sta[t].f * x + sta[t].s + 2*a*k*k - b*k + c;

	}

	printf("%lld\n" , DP[1] );

}
int main()
{
	solve();
	return 0;
}
