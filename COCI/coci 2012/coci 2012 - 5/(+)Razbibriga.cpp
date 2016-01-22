#include <algorithm>
#include <cstdio>
#include <cstring>
#include <map>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define TFOR(i,a,b) for(i=a; i>=b; i--)
#define f first
#define s second
#define pb push_back
#define all(x) x.begin(),x.end()
#define MAXN 300
using namespace std;
typedef pair < long long , long long > pcc;
int read(){ int res(0),sign(1); char c;
	while(1){ c = getchar(); if('0' <= c && c <= '9') { res = c - '0'; break; } else if(c == '-') { sign = -1; break; } }
	while(1){ c = getchar(); if('0' <= c && c <= '9') res = res*10 + c - '0'; else break; }
	return res * sign;
}
map < pcc , long long > mp;
long long A[MAXN][MAXN];
char str[MAXN];
long long C(long long n,int r)
{
	if(r == 1) return n;
	if(r == 2) return ( (n)*(n-1) );
	if(r == 3) return ( C(n,2) * (n-2) );
	if(r == 4) return ( C(n,3) * (n-3) );
}
void solve()
{
	long long N,a,b,c,d,i,k;
	N = read();
	FOR(i,1,N)
	{
		scanf("%s" , str );
		k = strlen( str );
		A[ str[0] ][ str[k-1] ]++;
	}

	map < pcc , long long > :: iterator it;

	long long res(0) , t;

	FOR(a,'A','Z')
		FOR(b,'A','Z')
			FOR(c,'A','Z')
				FOR(d,'A','Z')
				{
					if(!A[a][b] || !A[a][c] || !A[b][d] || !A[c][d]) continue;

					mp.clear();
					mp[ make_pair(a,b) ]++; mp[ make_pair(a,c) ]++;
					mp[ make_pair(b,d) ]++; mp[ make_pair(c,d) ]++;

					t = 1;

					for(it = mp.begin(); it != mp.end(); ++it)
						t *= C( A[ it->f.f ][ it->f.s ] , it->s );

					res += t;

				}

	printf("%lld\n" , res );

}
int main()
{
	solve();
	return 0;
}
