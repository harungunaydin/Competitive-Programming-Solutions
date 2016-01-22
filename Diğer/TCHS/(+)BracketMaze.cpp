#include <iostream>
#include <cstdio>
#include <cstring>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define F(x) ( (x == '(') ? 1 : (x == ')') ? -1 : 0 )
#define MAXN 15
using namespace std;
typedef pair < int , int > pii;
int N;
long long DP[MAXN][MAXN][MAXN][50];
char A[MAXN][MAXN][MAXN];
long long dp(int x,int y,int z,int t)
{
	if(x > N || y > N || z > N || t < 0) return 0;
	long long &ret = DP[x][y][z][t];
	if(ret != -1) return ret;
	if(x == N && y == N && z == N) return !t;
	ret  = dp(x+1,y,z,t + F(A[x+1][y][z]));
	ret += dp(x,y+1,z,t + F(A[x][y+1][z]));
	ret += dp(x,y,z+1,t + F(A[x][y][z+1]));
	return ret;
}
void solve()
{
	memset( DP , -1 , sizeof DP );
	string str = "",tmp;
	int T,i,j,k,s(0);
	scanf("%d",&T);
	FOR(i,1,T)
	{
		cin >> tmp;
		str += tmp;
	}
	scanf("%d",&N);
	FOR(i,1,N)
		FOR(j,1,N)
			FOR(k,1,N)
				A[i][j][k] = str[s++];
	long long t = (str[0] == '(') ? 1 : (str[0] == ')') ? -1 : 0;
	t = dp(1,1,1,t);
	if(t > 1e9) t = -1;
	printf("%lld\n" , t );
}
int main()
{
	solve();
	return 0;
}
