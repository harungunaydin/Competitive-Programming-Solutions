#include <iostream>
#include <cstdio>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define MAXN 100
using namespace std;
int DP[3*MAXN+5][3*MAXN+5];
bool A[3*MAXN+5][3*MAXN+5];
int dp(int bas,int son)
{
	if(bas >= son) return 0;
	if(DP[bas][son] != -1) return DP[bas][son];
	int i,res(0);
	FOR(i,bas+1,son-1)
		res = max( res , dp(bas,i) + dp(i,son) + A[bas][son]);
	return DP[bas][son] = res;
}
void solve()
{
	int N,c,i,j,r;
	scanf("%d",&N);
	FOR(i,1,N)
	{
		scanf("%d %d",&c,&r);
		c+=MAXN;
		A[c-r][c+r] = true;
	}
	FOR(i,0,3*MAXN)
		FOR(j,0,3*MAXN)
			DP[i][j] = -1;
	printf("%d\n",N - dp(0,3*MAXN));
}
int main()
{
	solve();
	return 0;
}
