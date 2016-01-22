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
int read(){ int res(0),sign(1); char c;
	while(1){ c = getchar(); if('0' <= c && c <= '9') { res = c - '0'; break; } else if(c == '-') { sign = -1; break; } }
	while(1){ c = getchar(); if('0' <= c && c <= '9') res = res*10 + c - '0'; else break; }
	return res * sign;
}
int N;
int DP[MAXN][2];
char A[MAXN];
inline int dp(int x,bool k)
{
	int &ret = DP[x][k];
	if(ret) return ret;
	if(x == N + 1) return ret = k;
	if(A[x] == 'A' && !k) return ret = min( dp(x+1,0) , dp(x+1,1) + 1 );
	if(A[x] == 'B' && k)  return ret = min( dp(x+1,1) , dp(x+1,0) + 1 );
	return ret = min( dp(x+1,0) , dp(x+1,1) ) + 1;
}
void solve()
{
	N = read();
	scanf("%s" , A + 1 );
	int i;
	TFOR(i,N,1)
	{
		dp(i,0);
		dp(i,1);
	}
	if(A[1] == 'A')
		printf("%d\n" , min( dp(2,0) , dp(2,1) + 1 ) );
	else
		printf("%d\n" , min( dp(2,1) , dp(2,0) + 1 ) );
}
int main()
{
	solve();
	return 0;
}
