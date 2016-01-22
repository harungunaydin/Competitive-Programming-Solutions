#include <iostream>
#include <cstdio>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define INF 10000000
#define MAXN 101
using namespace std;
inline int Abs( int a ) { return a > 0 ? a : -a; }
inline int Min( int a , int b ) { return a < b ? a : b; }
int E,N;
int A[MAXN] , B[MAXN] , C[MAXN];
int D[MAXN][MAXN],DP[MAXN][MAXN];
void init()
{
	int i,j,k;
	FOR(i,1,N)
	{
		FOR(j,1,i-1)
			B[i] += 2 * Abs( A[i] - A[j] );
		FOR(j,i+1,N)
			C[i] += 2 * Abs( A[i] - A[j] );
		FOR(j,1,N)
			FOR(k,i+1,j-1)
				D[i][j] += Abs( 2 * A[k] - A[i] - A[j] );
	}
}
int dp(int rem,int last)
{
	int &ret = DP[rem][last];
	if(ret) return ret;
	if(!rem) return ret = C[last];
	if(last == N) return ret = INF;
	ret = INF;
	int i;
	if(!last)
		FOR(i,1,N)
			ret = Min( ret , dp(rem-1,i) + B[i] );
	else
		FOR(i,last+1,N)
			ret = Min( ret , dp(rem-1,i) + D[last][i] );
	return ret;
}
void solve()
{
	int i;
	scanf("%d %d",&N,&E);
	FOR(i,1,N) scanf("%d",A+i);
	init();
	FOR(i,1,N)
		if(dp(i,0) <= E)
		{
			printf("%d %d\n" , i , dp(i,0) );
			break;
		}
}
int main()
{
	solve();
	return 0;
}
