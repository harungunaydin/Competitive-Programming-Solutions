#include <algorithm>
#include <cstdio>
#include <queue>
#include <vector>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define MOD 1000000000ll
#define MAXN 10005
using namespace std;
vector < int > f;
vector < int > G[MAXN] , GT[MAXN] , SCC[MAXN];
int M,N,S,vis;
int B[MAXN] , visited[MAXN];
void dfs1(int x)
{
	visited[x] = vis;
	vector < int > :: iterator it;
	for(it = G[x].begin(); it != G[x].end(); ++it)
		if(visited[*it] != vis)
			dfs1(*it);
	f.push_back(x);
}
void dfs2(int x)
{
	SCC[S].push_back(x);
	visited[x] = vis;
	vector < int > :: iterator it;
	for(it = GT[x].begin(); it != GT[x].end(); ++it)
		if(visited[*it] != vis)
			dfs2(*it);
}
bool C[MAXN] , H1[MAXN] , H2[MAXN];
void BFS1()
{
	vis++;
	queue < int > Q;
	vector < int > :: iterator it;
	int x;
	Q.push(1);
	while(!Q.empty())
	{
		x = Q.front(); Q.pop();

		H1[x] = true;

		for(it = G[x].begin(); it != G[x].end(); ++it)
			if(visited[*it] != vis)
			{
				Q.push(*it);
				visited[*it] = vis;
			}
	}
}
void BFS2()
{
	vis++;
	queue < int > Q;
	vector < int > :: iterator it;
	int x;
	Q.push(2);
	while(!Q.empty())
	{
		x = Q.front(); Q.pop();

		H2[x] = true;
		
		for(it = GT[x].begin(); it != GT[x].end(); ++it)
			if(visited[*it] != vis)
			{
				Q.push(*it);
				visited[*it] = vis;
			}
	}
}
long long RES[MAXN];
void solve()
{
	int a,b,i;
	scanf("%d %d",&N,&M);
	FOR(i,1,M)
	{
		scanf("%d %d",&a,&b);
		G[a].push_back(b);
		B[b]++;
		GT[b].push_back(a);
	}

	vis = 1;

	FOR(i,1,N)
		if(visited[i] != vis)
			dfs1(i);

	vis = 2;

	for(i = (int) f.size() - 1; i >= 0; i--)
		if(visited[f[i]] != vis)
		{
			S++;
			dfs2(f[i]);
		}

	vector < int > :: iterator it;

	FOR(i,1,S)
		for(it = SCC[i].begin(); it != SCC[i].end(); ++it)
			C[*it] = ( SCC[i].size() > 1 );

	BFS1();
	BFS2();

	FOR(i,1,N)
		if(!H1[i])
			for(it = G[i].begin(); it != G[i].end(); ++it)
				B[*it]--;

	if(!H1[2]) { printf("0\n"); return; }

	FOR(i,1,N)
		if(H1[i] && H2[i] && C[i])
		{
			printf("inf\n");
			return;
		}

	queue < int > Q;

	Q.push(1);

	int x;

	bool flag = false;

	RES[1] = 1ll;

	while(!Q.empty())
	{
		x = Q.front(); Q.pop();

		for(it = G[x].begin(); it != G[x].end(); ++it)
		{
			if(!H2[*it]) continue;

			RES[*it] += RES[x];

			if(RES[*it] >= MOD)
			{
				RES[*it] %= MOD;
				flag = true;
			}
			if(!(--B[*it]))
				Q.push(*it);
		}
	}

	if(flag)
	{
		long long a = RES[2];
		int s(0);
		while(a) { s++; a /= 10; }

		FOR(i,1,9-s) printf("0");
		printf("%lld\n" , RES[2] );

	}
	else
		printf("%lld\n" , RES[2] );

}
int main()
{
	solve();
	return 0;
}
