#include <iostream>
#include <cstdio>
#include <cstring>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define MAXN 16
using namespace std;
typedef pair < int , int > pii;
inline int Max( int a , int b ) { return a > b ? a : b; }
int M,N;
int DP[1<<MAXN];
int A[MAXN][MAXN];
int dp(int k)
{
	int &ret = DP[k];
	if(ret) return ret;
	if(k == M) return ret = 0;
	int i,x(0),t(k);
	while(t) { x++; t -= t&-t; }
	t = 1;
	FOR2(i,N)
	{
		if(!(k&t))
			ret = Max( ret , dp(k | t) + A[x][i] );
		t <<= 1;
	}
	return ret;
}
void solve()
{
	memset( DP , 0 , sizeof DP );
	scanf("%d",&N);
	M = (1<<N) - 1;
	int i,j,res(0);
	FOR2(i,N)
		FOR2(j,N)
			scanf("%d",A[i]+j);
	FOR2(i,N)
		res = Max( res , dp(1<<i) + A[0][i] );
	printf("%d\n" , res );
}
int main()
{
	int T,i;
	scanf("%d",&T);
	FOR(i,1,T)
	{
		printf("Case %d: ",i);
		solve();
	}
	return 0;
}
