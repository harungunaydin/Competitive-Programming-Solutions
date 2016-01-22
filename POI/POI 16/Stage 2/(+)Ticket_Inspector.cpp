#include <algorithm>
#include <cstdio>
#include <cstring>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define TFOR(i,a,b) for(i=a; i>=b; i--)
#define H(x1,y1,x2,y2) ( T[x2][y2] - T[x2][y1-1] - T[x1-1][y2] + T[x1-1][y1-1] )
#define all(x) x.begin(),x.end()
#define MAXK 53
#define MAXN 603
using namespace std;
typedef pair < int , int > pii;
int read()
{
	int res(0),sign(1);
	char c;
	while(1)
	{
		c = getchar();
		if('0' <= c && c <= '9') { res = c - '0'; break; }
		else if(c == '-') { sign = -1; break; }
	}
	while(1)
	{
		c = getchar();
		if('0' <= c && c <= '9') res = res*10 + c - '0';
		else break;
	}
	return res * sign;
}
int K,N;
int T[MAXN][MAXN];
int DP[2][MAXN][MAXK];
int hallet(int x,int pre)
{
	int t = H(1,x+1,x,N);
	if(pre) t -= H(1,x+1,pre,N);
	return t;
}
bool dp()
{
	int cur(0),k,pre,ret,x;
	TFOR(x,N+1,1)
	{
		cur = !cur;
		FOR(pre,0,x-1)
			FOR(k,0,K)
			{
				if(!k) ret = 0;
				else if(x == N + 1) ret = -20000000;
				else
					ret = max( DP[!cur][pre][k] , DP[!cur][x][k-1] + hallet(x,pre) );

				DP[cur][pre][k] = ret;
			}
	}

	return cur;
}

void yol(int cur,int x,int pre,int k)
{
	if(!k) return;
	if(x == N + 1) return;

	int t1 = DP[!cur][pre][k];
	int t2 = DP[!cur][x][k-1] + hallet(x,pre);
	if(t1 > t2) yol(!cur,x+1,pre,k);
	else
	{
		printf("%d " , x );
		yol(!cur,x+1,x,k-1);
	}
}
void solve()
{
	memset( DP , -1 , sizeof DP );
	int i,j;
	N = read(); K = read();

	FOR(i,1,N)
		FOR(j,i+1,N)
			T[i][j] = read();

	FOR(i,1,N)
		FOR(j,1,N)
			T[i][j] += T[i][j-1] + T[i-1][j] - T[i-1][j-1];

	yol(dp(),1,0,K);

}
int main()
{
	solve();
	return 0;
}
