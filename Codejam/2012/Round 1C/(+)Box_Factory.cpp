#include <iostream>
#include <cstdio>
#include <map>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define f first
#define s second
#define MAXN 105
using namespace std;
typedef pair < long long , long long > pll;
inline long long Max( long long a , long long b ) { return a > b ? a : b; }
inline long long Min( long long a , long long b ) { return a < b ? a : b; }
map < long long , long long > DP[MAXN][MAXN][3];
pll P[MAXN] , P2[MAXN];
int M,N;
long long dp( int a , int b , int k , long long t)
{
	if(a == N + 1 || b == M + 1) return 0;
	
	if(DP[a][b][k].find(t) != DP[a][b][k].end()) 
		return DP[a][b][k][t];

	long long &ret = DP[a][b][k][t];

	if(k == 0)
	{
		if(P[a].s == P2[b].s)
		{
			if(P[a].f < P2[b].f) return ret = dp( a+1,b,2,P2[b].f - P[a].f ) + P[a].f;
			if(P[a].f == P2[b].f) return ret = dp(a+1,b+1,0,0) + P[a].f;
			return ret = dp(a,b+1,1,P[a].f - P2[b].f) + P2[b].f;
		}
		else
			return ret = Max( dp(a+1,b,0,0) , dp(a,b+1,0,0) );
	}

	if(k == 1)
	{
		if(P[a].s == P2[b].s)
		{
			if(t < P2[b].f) return ret = dp(a+1,b,2,P2[b].f - t) + t;
			if(t == P2[b].f) return ret = dp(a+1,b+1,0,0) + t;
			return ret = dp(a,b+1,1,t - P2[b].f) + P2[b].f;
		}
		else
			return ret = Max( dp(a+1,b,0,0) , dp(a,b+1,1,t) );
	}
	if(k == 2)
	{
		if(P[a].s == P2[b].s)
		{
			if(P[a].f < t) return ret = dp(a+1,b,2,t - P[a].f) + P[a].f;
			if(P[a].f == t) return ret = dp(a+1,b+1,0,0) + t;
			return ret = dp(a,b+1,1,P[a].f - t) + t;
		}
		else
			return ret = Max( dp(a+1,b,2,t) , dp(a,b+1,0,0) );
	}
}
void solve()
{
	int i,j,k;
	
	scanf("%d %d",&N,&M);
	FOR(i,1,N) scanf("%lld %lld" , &P[i].f , &P[i].s );
	FOR(i,1,M) scanf("%lld %lld" , &P2[i].f , &P2[i].s );

	FOR(i,0,N+1)
		FOR(j,0,M+1)
			FOR(k,0,2)
				DP[i][j][k].clear();
	printf("%lld\n" , dp(1,1,0,0) );
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
