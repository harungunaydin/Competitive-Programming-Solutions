#include <cstdio>
#include <vector>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define MAXN 10001
using namespace std;
vector < int > G[MAXN];
int N,dis,res,vis;
int A[MAXN],M[MAXN],S[MAXN],visited[MAXN];
void dfs(int x,int pre)
{
	S[x] = ++dis;
	M[x] = dis;
	visited[x] = vis;
	int s(0);
	vector < int > :: iterator it;
	for(it = G[x].begin(); it != G[x].end(); ++it)
		if(visited[*it] != vis)
		{
			if(x == 1 && s == 1) res++;
			s++;
			dfs(*it,x);
			if(M[*it] < M[x]) M[x] = M[*it];
			
			if(M[*it] >= S[x])
				A[x] = vis;
		}
		else if(x != pre && S[*it] < M[x])
			M[x] = S[*it];
}
void solve()
{
	res = dis = 0;
	int M,a,b,i;
	scanf("%d %d",&N,&M);
	FOR(i,1,N) G[i].clear();
	FOR(i,1,M)
	{
		scanf("%d %d",&a,&b);
		G[a].push_back(b);
		G[b].push_back(a);
	}

	dfs(1,-1);

	FOR(i,2,N)
		res += (A[i] == vis);

	printf("%d\n" , res );

}
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		printf("Case %d: " , ++vis );
		solve();
	}
	return 0;
}
