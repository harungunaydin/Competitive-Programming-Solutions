#include <iostream>
#include <cstdio>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define f first
#define s second
#define all(x) x.begin(),x.end()
#define MAXN 1000
using namespace std;
typedef pair < int , int > pii;
pii A[MAXN+5];
int N;
int DP[MAXN+5][2];
int dp(int x,int pre)
{
	if(x == N + 1) return 0;
	if(DP[x][pre]) return DP[x][pre];
	int res;
	if(pre ==-1) res = max( dp(x+1,0) + A[x].f , dp(x+1,1) + A[x].s);
	if(pre == 0) res = max( dp(x+1,0) + A[x].f + abs(A[x].s - A[x-1].s), dp(x+1,1) + A[x].s + abs(A[x].f - A[x-1].s));
	if(pre == 1) res = max( dp(x+1,0) + A[x].f + abs(A[x].s - A[x-1].f), dp(x+1,1) + A[x].s + abs(A[x].f - A[x-1].f));
	return DP[x][pre] = res;
}
void solve()
{
	int i;
	scanf("%d",&N);
	FOR(i,1,N)
		scanf("%d %d",&A[i].f,&A[i].s);
	printf("%d\n",dp(1,-1));
}
int main()
{
	solve();
	return 0;
}
