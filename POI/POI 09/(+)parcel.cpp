#include <algorithm>
#include <cstdio>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define TFOR(i,a,b) for(i=a; i>=b; i--)
#define f first
#define s second
#define pb push_back
#define all(x) x.begin(),x.end()
#define MAXN 2005
#define MAXT 4100
using namespace std;
typedef pair < int , int > pii;
int read(){ int res(0),sign(1); char c;
	while(1){ c = getchar(); if('0' <= c && c <= '9') { res = c - '0'; break; } else if(c == '-') { sign = -1; break; } }
	while(1){ c = getchar(); if('0' <= c && c <= '9') res = res*10 + c - '0'; else break; }
	return res * sign;
}
pii ST[MAXT];
int N;
int H[MAXN][MAXN];
bool A[MAXN][MAXN];
inline pii init(int pos,int s,int e,int k)
{
	if(s == e) return ST[pos] = make_pair( H[k][s] , s );

	int m = ( s + e ) >> 1;
	int sol = pos << 1;
	int sag = sol | 1;

	pii p1 = init(sol,s,m,k);
	pii p2 = init(sag,m+1,e,k);

	return ST[pos] = (p1.f < p2.f) ? p1 : p2;

}
inline pii find(int pos,int s,int e,int a,int b)
{
	if(a > e || b < s) return make_pair(10000,10000);
	if(a <= s && e <= b) return ST[pos];
	
	int m = ( s + e ) >> 1;
	int sol = pos << 1;
	int sag = sol | 1;

	pii p1 = find(sol,s,m,a,b);
	pii p2 = find(sag,m+1,e,a,b);

	return (p1.f < p2.f) ? p1 : p2;

}
int res;
inline void dq(int bas,int son)
{
	pii p = find(1,1,N,bas,son);

	res = max( res , (son - bas + 1) * p.f );

	if(bas < p.s) dq(bas,p.s-1);
	if(p.s < son) dq(p.s+1,son);

}
void solve()
{
	int i,j;
	N = read();
	FOR(i,1,N)
	{
		FOR(j,1,N)
			H[i][j] = read() ? 0 : H[i-1][j] + 1;

		init(1,1,N,i);

		dq(1,N);

	}

	printf("%d\n" , res );

}
int main()
{
	solve();
	return 0;
}
