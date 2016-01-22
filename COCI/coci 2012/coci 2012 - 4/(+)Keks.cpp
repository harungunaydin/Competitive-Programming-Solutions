#include <algorithm>
#include <cstdio>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define TFOR(i,a,b) for(i=a; i>=b; i--)
#define f first
#define s second
#define pb push_back
#define all(x) x.begin(),x.end()
#define MAXN 500005
#define MAXT 2000050
using namespace std;
typedef pair < int , int > pii;
int read(){ int res(0),sign(1); char c;
	while(1){ c = getchar(); if('0' <= c && c <= '9') { res = c - '0'; break; } else if(c == '-') { sign = -1; break; } }
	while(1){ c = getchar(); if('0' <= c && c <= '9') res = res*10 + c - '0'; else break; }
	return res * sign;
}
pii ST[MAXT];
int K,N;
int A[MAXN];
pii init(int pos,int s,int e)
{
	if(s == e) return ST[pos] = make_pair( A[s] , s );

	int m = ( s + e ) >> 1;
	int sol = pos << 1;
	int sag = sol | 1;

	pii p1 = init(sol,s,m);
	pii p2 = init(sag,m+1,e);

	return ST[pos] = (p1.f >= p2.f) ? p1 : p2;
}
pii find(int pos,int s,int e,int a,int b)
{
	if(a > e || b < s) return make_pair(-1,-1);
	if(a <= s && e <= b) return ST[pos];
	
	int m = ( s + e ) >> 1;
	int sol = pos << 1;
	int sag = sol | 1;

	pii p1 = find(sol,s,m,a,b);
	pii p2 = find(sag,m+1,e,a,b);

	return p1.f >= p2.f ? p1 : p2;

}
void solve()
{
	N = read(); K = read();
	int i;
	char c;
	FOR(i,1,N)
	{
		scanf(" %c" , &c );
		A[i] = c - '0';
	}
	init(1,1,N);
	int a(1);
	while(a <= N)
	{
		pii p = find(1,1,N,a,a+K);
		printf("%d" , p.f );
		K -= p.s - a;
		a = p.s + 1;
	}
	printf("\n");

}
int main()
{
	solve();
	return 0;
}
