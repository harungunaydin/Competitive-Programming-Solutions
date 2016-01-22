#include <iostream>
#include <algorithm>
#include <cstdio>
#include <queue>
#include <vector>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define f first
#define s second
#define all(x) x.begin(),x.end()
#define EKLE(x,y,s) pq.push(make_pair(-(s),make_pair(x,y)));
#define BAK(x,y,s)  { x = pq.top().s.f; y = pq.top().s.s; s = - pq.top().f; pq.pop(); }
#define MAXN 1024
using namespace std;
typedef pair < int , int > pii;
priority_queue < pair < int , pii > > pq;
vector < pii > G[MAXN+5];
vector < int > V[MAXN+5];
int N;
bool visited[MAXN+5];
void solve()
{
	vector < pii > :: iterator it;
	vector < int > :: iterator it2;
	int a,i,j,from,s,x;
	scanf("%d",&N);
	FOR(i,1,N)
	{
		FOR(j,i+1,N)
		{
			scanf("%d",&a);
			G[i].push_back(make_pair(a,j));
			G[j].push_back(make_pair(a,i));
		}
	}
	EKLE(0,1,0);
	while(!pq.empty())
	{
		BAK(from,x,s);
		if(visited[x]) continue;
		visited[x] = true;
		V[from].push_back(x);
		if(from) V[x].push_back(from);
		for(it = G[x].begin(); it != G[x].end(); ++it)
				EKLE(x,it->s,it->f);
	}
	FOR(i,1,N)
	{
		printf("%d", (int) V[i].size() );
		sort(all(V[i]));
		for(it2 = V[i].begin(); it2 != V[i].end(); ++it2)
			printf(" %d",*it2);
		printf("\n");
	}
}
int main()
{
	solve();
	return 0;
}
