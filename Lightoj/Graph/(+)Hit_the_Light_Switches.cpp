#include <cstdio>
#include <cstring>
#include <vector>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define MAXN 10005
using namespace std;
vector < int > finish;
vector < int > G[MAXN],GT[MAXN];
int M,N,grup,vis;
int A[MAXN],B[MAXN],visited[MAXN];
void dfs(int x)
{
	visited[x] = vis;
	vector < int > :: iterator it;
	for(it = G[x].begin(); it != G[x].end(); ++it)
		if(visited[*it] != vis)
			dfs(*it);
	finish.push_back(x);
}
void dfs2(int x)
{
	visited[x] = vis;
	A[x] = grup;
	vector < int > :: iterator it;
	for(it = GT[x].begin(); it != GT[x].end(); ++it)
		if(visited[*it] != vis)
			dfs2(*it);
}
void solve()
{
	int a,b,i,res(0);
	scanf("%d %d",&N,&M);
	FOR(i,1,N) { G[i].clear(); GT[i].clear(); }
	FOR(i,1,M)
	{
		scanf("%d %d",&a,&b);
		G[a].push_back(b);
		GT[b].push_back(a);
	}
	vis++;
	finish.clear();
	FOR(i,1,N)
		if(visited[i] != vis)
			dfs(i);

	grup = 0;
	vis++;
	vector < int > :: reverse_iterator rit;
	for(rit = finish.rbegin(); rit != finish.rend(); ++rit)
		if(visited[*rit] != vis)
		{
			grup++;
			dfs2(*rit);
		}

	vector < int > :: iterator it;
	FOR(i,1,N)
		for(it = G[i].begin(); it != G[i].end(); ++it)
			if(A[i] != A[*it])
				B[A[*it]] = vis;

	FOR(i,1,grup) res += (B[i] != vis);

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
