#include <iostream>
#include <cstdio>
#include <map>
#include <queue>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define EKLE_PQ(x,s) pq.push(make_pair(-(s),x))
#define BAK_PQ(x,s) { x = pq.top().second; s = - pq.top().first; pq.pop(); }
#define EKLE(x) { Q.push(x); visited[x] = vis; }
#define BAK(x) { x = Q.front(); Q.pop(); }
#define INF 2000000000
#define MAXN 30000
using namespace std;
typedef pair < int , int > pii;
priority_queue < pii > pq;
queue < int > Q;
map < pii , int > mp;
vector <int> V[MAXN+5];
int N,M,vis;
int A[MAXN+5],d[MAXN+5],visited[MAXN+5];
bool BFS(int a,int b)
{
	vector < int > :: iterator it;
	int x;
	vis++;
	EKLE(a);
	while(!Q.empty())
	{
		BAK(x);
		if(x == b) return 1;
		for(it = V[x].begin(); it != V[x].end(); ++it)
			if(visited[*it] < vis)
				EKLE(*it);
	}
	return 0;
}
int dijkstra(int a,int b)
{
	int x,s;
	vector < int > :: iterator it;
	if(N&1 && mp[make_pair(a,b)]) return mp[make_pair(a,b)];
	fill(d+1,d+N+1,INF);
	d[a] = 0;
	EKLE_PQ(a,0);
	while(!pq.empty())
	{
		BAK_PQ(x,s);
		for(it = V[x].begin(); it != V[x].end(); ++it)
			if(s + A[*it] < d[*it])
			{
				d[*it] = s + A[*it];
				EKLE_PQ(*it,d[*it]);
			}
	}
	return d[b] + A[a];
}
void solve()
{
	int a,b,i;
	char S[20];
	scanf("%d",&N);
	FOR(i,1,N)
		scanf("%d",A+i);
	scanf("%d",&M);
	FOR2(i,M)
	{
			scanf("%s %d %d",S,&a,&b);
			if(S[0] == 'e')
			{
				a = dijkstra(a,b);
				(a < INF) ? printf("%d\n",a) : printf("impossible\n");
			}
			if(S[0] == 'b')
			{
				int k = BFS(a,b);
				if(k)
					printf("no\n");
				else
				{
					printf("yes\n");
					V[a].push_back(b);
					V[b].push_back(a);
				}
			}
			if(S[0] == 'p')
				A[a] = b;
	}
}
int main()
{
	solve();
	return 0;
}
