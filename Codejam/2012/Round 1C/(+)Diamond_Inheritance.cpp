#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define TFOR(i,a,b) for(i=a; i>=b; i--)
#define MAXN 1005
using namespace std;
vector < int > G[MAXN];
int N;
int B[MAXN];
bool BFS(int x)
{
	queue < int > Q;
	memset( B , 0 , sizeof B );
	vector < int > :: iterator it;
	Q.push(x);
	B[x] = 1;
	while(!Q.empty())
	{
		x = Q.front(); Q.pop();
		if(B[x] >= 2) return true;
		for(it = G[x].begin(); it != G[x].end(); ++it)
		{
			B[*it] += B[x];
			Q.push(*it);
		}
	}
	return false;
}
int solve()
{
	int a,i,j,s;
	scanf("%d",&N);
	FOR(i,1,N)
	{
		G[i].clear();
		scanf("%d",&s);
		FOR(j,1,s)
		{
			scanf("%d",&a);
			G[i].push_back(a);
		}
	}

	FOR(i,1,N)
		if(BFS(i))
			return true;

	return false;
}
int main()
{
	int T,i;
	scanf("%d",&T);
	FOR(i,1,T)
	{
		printf("Case #%d: ",i);
		solve() ? printf("Yes\n") : printf("No\n");
	}
	return 0;
}
