#include <algorithm>
#include <cstdio>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define TFOR(i,a,b) for(i=a; i>=b; i--)
#define all(x) x.begin(),x.end()
#define MAXN 1005
using namespace std;
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
int M,N;
long long dp_count[MAXN][MAXN] , dp_sum[MAXN][MAXN];
long long col_sum[MAXN][MAXN] , row_sum[MAXN][MAXN];
char A[MAXN][MAXN];
long long hallet(char c , bool k)
{
	long long res(0);
	int i,j;
	FOR(i,1,M)
		FOR(j,1,N)
		{
			dp_count[i][j] = dp_count[i][j-1] + dp_count[i-1][j] - dp_count[i-1][j-1];
			dp_sum[i][j] = dp_sum[i-1][j-1] + dp_count[i-1][j-1];
			col_sum[i][j] = col_sum[i-1][j] + dp_count[i-1][j] - dp_count[i-1][j-1];
			row_sum[i][j] = row_sum[i][j-1] + dp_count[i][j-1] - dp_count[i-1][j-1];
			dp_sum[i][j] += col_sum[i][j] + row_sum[i][j];

			if(A[i][j] == c)
			{
				res += dp_sum[i-1][j-1] + dp_count[i-1][j-1] + k * ( row_sum[i][j] + col_sum[i][j] );
				dp_count[i][j]++;
			}
		}

	return res;
}
void reverse()
{
	int i;
	FOR(i,1,M)
		reverse( A[i]+1 , A[i]+N+1 );
}
long long f(char c)
{
	long long res(0);
	res += hallet(c,0);
	reverse();
	res += hallet(c,1);
	reverse();
	return res;
}
void solve()
{
	int i;
	M = read(); N = read();
	FOR(i,1,M)
		scanf("%s" , A[i] + 1 );

	printf("%lld %lld\n" , f('M') , f('S') );

}
int main()
{
	solve();
	return 0;
}
