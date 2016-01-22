#include <iostream>
#include <cstdio>
#include <cstring>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define TFOR(i,a,b) for(i=a; i>=b; i--)
#define ABS(x) ( (x) > 0 ? (x) : -(x) )
#define MAXN 50
using namespace std;
string str;
int N;
long long DP[MAXN][2][3][5][7];
long long dp(int x,int k2,int k3,int k5,int k7)
{
	long long &ret = DP[x][k2][k3][k5][k7];
	if(ret != -1) return ret;

	if(x == N) return ret = ( (!k2) || (!k3) || (!k5) || (!k7) );

	ret = 0;
	
	int a(0),b(0),c(0),d(0),i,t;
	
	for(i = x; i < N; i++)
	{
		t = str[i] - '0';

		a = ( a * 10 + t ) % 2;
		b = ( b * 10 + t ) % 3;
		c = ( c * 10 + t ) % 5;
		d = ( d * 10 + t ) % 7;

		ret += dp(i+1,(k2+a)%2,(k3+b)%3,(k5+c)%5,(k7+d)%7);
	}

	a = b = c = d = 0;

	if(x)
		for(i = x; i < N; i++)
		{
			t = str[i] - '0';

			a = ( a * 10 + t ) % 2;
			b = ( b * 10 + t ) % 3;
			c = ( c * 10 + t ) % 5;
			d = ( d * 10 + t ) % 7;
	
			ret += dp(i+1 , (k2-a+20)%2 , (k3-b+30)%3 , (k5-c+50)%5 , (k7-d+70)%7 );
		}

	return ret;
}
void solve()
{
	memset( DP , -1 , sizeof DP );
	cin >> str;
	N = str.size();
	printf("%lld\n" , dp(0,0,0,0,0) );
}
int main()
{
	int T,i;
	scanf("%d",&T);
	FOR(i,1,T)
	{
		printf("Case #%d: ",i);
		solve();
	}
	return 0;
}
