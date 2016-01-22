#include <algorithm>
#include <cstdio>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define TFOR(i,a,b) for(i=a; i>=b; i--)
#define KONTROL(x,y) (1 <= x && x <= N && 1 <= y && y <= N) 
#define MAXN 405
using namespace std;
typedef pair < int , int > pii;
int read(){ int res(0),sign(1); char c;
	while(1){ c = getchar(); if('0' <= c && c <= '9') { res = c - '0'; break; } else if(c == '-') { sign = -1; break; } }
	while(1){ c = getchar(); if('0' <= c && c <= '9') res = res*10 + c - '0'; else break; }
	return res * sign;
}
int N;
int A[MAXN][MAXN];
void solve()
{
	int i,j,k,res(0),s(0),x,y;
	N = read();
	FOR(i,1,N)
		FOR(j,1,N)
			A[i][j] = read();

	FOR(i,1,N)
		FOR(j,1,N)
		{
			x = i;
			y = j;

			k = 1;
			s = 0;
			while( KONTROL(i-k,j-k) && KONTROL(i+k,j+k) && KONTROL(i-k,j+k) && KONTROL(i+k,j-k) )
			{
				s += A[i-k][j-k] + A[i+k][j+k] - A[i-k][j+k] - A[i+k][j-k];
				if(s > res) res = s;
				k++;
			}
			k = 1;
			s = 0;
			while( KONTROL(i-k+1,j-k+1) && KONTROL(i+k,j+k) && KONTROL(i-k+1,j+k) && KONTROL(i+k,j-k+1) )
			{
				s += A[i-k+1][j-k+1] + A[i+k][j+k] - A[i-k+1][j+k] - A[i+k][j-k+1];
				if(s > res) res = s;
				k++;
			}
		}

	printf("%d\n" , res );

}
int main()
{
	solve();
	return 0;
}
