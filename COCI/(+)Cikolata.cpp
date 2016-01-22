#include <iostream>
#include <algorithm>
#include <cstdio>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define all(x) x.begin(),x.end()
#define MAXN 1000
using namespace std;
int M,N;
int A[MAXN+5],B[MAXN+5];
int DP[MAXN+5][MAXN+5];
int dp(int x,int y)
{
	if(DP[x][y]) return DP[x][y];
	if(x == N && y == M) return 0;
	if(x == N) return DP[x][y] = dp(x,y+1) + B[y] * x;
	if(y == M) return DP[x][y] = dp(x+1,y) + A[x] * y;
	return DP[x][y] = min( dp(x+1,y) + A[x] * y, dp(x,y+1) + B[y] * x );
}
void solve()
{
	int i;
	scanf("%d %d",&N,&M);
	FOR(i,1,N-1) scanf("%d",A+i);
	FOR(i,1,M-1) scanf("%d",B+i);
	sort(A+1,A+N,greater<int> ());
	sort(B+1,B+M,greater<int> ());
	printf("%d\n" , dp(1,1) );
}
int main()
{
	solve();
	return 0;
}
