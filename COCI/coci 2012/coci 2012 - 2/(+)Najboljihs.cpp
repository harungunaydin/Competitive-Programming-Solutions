#include <algorithm>
#include <cstdio>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define TFOR(i,a,b) for(i=a; i>=b; i--)
#define f first
#define s second
#define pb push_back
#define all(x) x.begin(),x.end()
#define MAXN 
using namespace std;
typedef pair < int , int > pii;
int read(){ int res(0),sign(1); char c;
	while(1){ c = getchar(); if('0' <= c && c <= '9') { res = c - '0'; break; } else if(c == '-') { sign = -1; break; } }
	while(1){ c = getchar(); if('0' <= c && c <= '9') res = res*10 + c - '0'; else break; }
	return res * sign;
}
int A[8];
void solve()
{
	int a,b,c,d,e,i,maxi(0);
	int a2,b2,c2,d2,e2;
	FOR(i,1,8)
		scanf("%d" , A+i );
	FOR(a,1,8)
		FOR(b,a+1,8)
			FOR(c,b+1,8)
				FOR(d,c+1,8)
					FOR(e,d+1,8)
						if(A[a] + A[b] + A[c] + A[d] + A[e] > maxi)
						{
							maxi = A[a] + A[b] + A[c] + A[d] + A[e];
							a2 = a; b2 = b; c2 = c; d2 = d; e2 = e;
						}

	printf("%d\n%d %d %d %d %d\n" , maxi , a2 , b2 , c2 , d2 , e2 );

}
int main()
{
	solve();
	return 0;
}
