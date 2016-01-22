#include <algorithm>
#include <cstdio>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define TFOR(i,a,b) for(i=a; i>=b; i--)
#define f first
#define s second
#define pb push_back
#define all(x) x.begin(),x.end()
#define MAXN 105
using namespace std;
typedef pair < int , int > pii;
int read(){ int res(0),sign(1); char c;
	while(1){ c = getchar(); if('0' <= c && c <= '9') { res = c - '0'; break; } else if(c == '-') { sign = -1; break; } }
	while(1){ c = getchar(); if('0' <= c && c <= '9') res = res*10 + c - '0'; else break; }
	return res * sign;
}
int M,N;
int A[MAXN];
void solve()
{
	int i,j,k,res(0);
	N = read(); M = read();
	FOR(i,1,N)
		A[i] = read();

	FOR(i,1,N)
		FOR(j,i+1,N)
			FOR(k,j+1,N)
				if(A[i] + A[j] + A[k] <= M)
					res = max( res , A[i] + A[j] + A[k] );

	printf("%d\n" , res );

}
int main()
{
	solve();
	return 0;
}
