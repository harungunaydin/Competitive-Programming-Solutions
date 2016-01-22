#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define TFOR(i,a,b) for(i=a; i>=b; i--)
#define f first
#define s second
#define pb push_back
#define all(x) x.begin(),x.end()
#define MAXN 15
using namespace std;
typedef pair < int , int > pii;
int read(){ int res(0),sign(1); char c;
	while(1){ c = getchar(); if('0' <= c && c <= '9') { res = c - '0'; break; } else if(c == '-') { sign = -1; break; } }
	while(1){ c = getchar(); if('0' <= c && c <= '9') res = res*10 + c - '0'; else break; }
	return res * sign;
}
int M,N;
int yon[4][2] = { {1,0},{0,1},{-1,0},{0,-1} };
char A[MAXN][MAXN];
bool solve()
{
	int i,j,k,s;
	M = read(); N = read();
	FOR(i,1,M)
		scanf("%s" , A[i] + 1 );

	FOR(i,1,M)
		FOR(j,1,N)
		{
			if(A[i][j] != '.') continue;
			s = 0;
			FOR2(k,4)
				if( A[i+yon[k][0]][j+yon[k][1]] != '.' )
					s++;

			if(s >= 3) return true;
		}

	return false;

}
int main()
{
	printf("%d\n" , solve() );
	return 0;
}
