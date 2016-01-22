#include <algorithm>
#include <cstdio>
#include <vector>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define TFOR(i,a,b) for(i=a; i>=b; i--)
#define f first
#define s second
#define pb push_back
#define all(x) x.begin(),x.end()
#define MAXN 500005
using namespace std;
typedef pair < int , int > pii;
int read(){ int res(0),sign(1); char c;
	while(1){ c = getchar(); if('0' <= c && c <= '9') { res = c - '0'; break; } else if(c == '-') { sign = -1; break; } }
	while(1){ c = getchar(); if('0' <= c && c <= '9') res = res*10 + c - '0'; else break; }
	return res * sign;
}
vector < int > F;
vector < int > SCC[MAXN] , G[MAXN] , GT[MAXN] , V[MAXN];
int M,N,P,S,Start,vis;
int A[MAXN] , C[MAXN] , T[MAXN] , visited[MAXN];
bool B[MAXN] , H[MAXN];
inline void dfs1(int x)
{
	visited[x] = vis;
	vector < int > :: iterator it;
	for(it = G[x].begin(); it != G[x].end(); ++it)
		if(visited[*it] != vis)
			dfs1(*it);
	F.pb(x);
}
inline void dfs2(int x)
{
	SCC[S].pb(x);
	C[x] = S;
	visited[x] = vis;
	vector < int > :: iterator it;
	for(it = GT[x].begin(); it != GT[x].end(); ++it)
		if(visited[*it] != vis)
			dfs2(*it);
}
void Calc_SCC()
{
	int i,j;
	vis = 1;
	FOR(i,1,N)
		if(visited[i] != vis)
			dfs1(i);

	vis = 2;
	
	for(i = (int) F.size() - 1; i >= 0; i--)
		if(visited[ F[i] ] != vis)
		{
			S++;
			dfs2(F[i]);
		}

	vector < int > :: iterator it,it2;

	N = S;
	FOR(i,1,N)
	{
		vis++;
		for(it = SCC[i].begin(); it != SCC[i].end(); ++it)
		{
			T[i] += A[*it];
			if(B[*it]) H[i] = true;
			for(it2 = G[*it].begin(); it2 != G[*it].end(); ++it2)
				visited[ C[*it2] ] = vis;
		}

		FOR(j,1,N)
			if(i != j && visited[j] == vis)
				V[i].push_back(j);
	}
}
int DP[MAXN];
inline int dp(int x)
{
	int &ret = DP[x];
	if(ret) return ret;

	ret = -100000000;

	vector < int > :: iterator it;
	for(it = V[x].begin(); it != V[x].end(); ++it)
		ret = max( ret , dp(*it) );

	if(H[x] && ret < 0) return ret = T[x];

	return ret += T[x];

}
void solve()
{
	int a,b,i;
	N = read(); M = read();
	while(M--)
	{
		a = read(); b = read();
		G[a].pb(b);
		GT[b].pb(a);
	}
	FOR(i,1,N)
		A[i] = read();

	Start = read(); P = read();

	FOR(i,1,P)
	{
		scanf("%d",&a);
		B[a] = true;
	}

	Calc_SCC();

	printf("%d\n" , dp( C[Start] ) );

}
int main()
{
	solve();
	return 0;
}
