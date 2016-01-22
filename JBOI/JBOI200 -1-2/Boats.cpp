#include <iostream>
#include <cstdio>
#include <vector>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define all(x) x.begin(),x.end()
#define MAXN 100000
using namespace std;
vector < int > V[MAXN+5];
int N,maxi;
int DP[MAXN+5];
int dp(int x)
{
	if(x >= maxi) return 0;
	if(DP[x]) return DP[x];
	vector < int > :: iterator it;
	int res;
	res = dp(x+1);
	for(it = V[x].begin(); it != V[x].end(); ++it)
		res = max( res , dp(*it) + 1 );
	return DP[x] = res;
}
void solve()
{
	int a,b,i,mini(MAXN+5);
	scanf("%d",&N);
	FOR(i,1,N)
	{
		scanf("%d %d",&a,&b);
		mini = min( mini , b );
		maxi = max( maxi , a + b - 1 );
		V[b].push_back(a+b-1);
	}
	printf("%d\n",dp(mini));
}
int main()
{
	solve();
	return 0;
}
