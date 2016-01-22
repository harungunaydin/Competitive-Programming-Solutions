#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define f first
#define s second
#define EKLE(x,s) pq.push(make_pair(-(s),x))
#define BAK(x,s) { x = pq.top().s; s = - pq.top().f; pq.pop(); }
#define INF 20000000
#define MAXN 1000
using namespace std;
typedef pair < int , int > pii;
priority_queue < pii > pq;
vector < pii > G[MAXN+5];
int M,N;
int D[MAXN+5],S[MAXN+5];
void init_dijkstra()
{
	vector < pii > :: iterator it;
	int i,s,x;
	FOR(i,1,N) D[i] = INF;
	D[N] = 0;
	EKLE(N,0);
	while(!pq.empty())
	{
		BAK(x,s);
		for(it = G[x].begin(); it != G[x].end(); ++it)
			if(s + it->s < D[it->f])
			{
				S[it->f] = x;
				D[it->f] = s + it->s;
				EKLE(it->f,D[it->f]);
			}
	}
}
int dijkstra(int from,int to)
{
	vector < pii > :: iterator it;
	int i,s,x;
	FOR(i,1,N) D[i] = INF;
	D[N] = 0;
	EKLE(N,0);
	while(!pq.empty())
	{
		BAK(x,s);
		for(it = G[x].begin(); it != G[x].end(); ++it)
			if((from != x || to != it->f) && (from != it->f || to != x) && s + it->s < D[it->f])
			{
				D[it->f] = s + it->s;
				EKLE(it->f,D[it->f]);
			}
	}
	return D[1] >= INF ? 0 : D[1];
}
void read()
{
	scanf("%d %d",&N,&M);
	int a,b,c,i,j;
	FOR(i,1,M)
	{
		scanf("%d %d %d",&a,&b,&c);
		G[a].push_back(make_pair(b,c));
		G[b].push_back(make_pair(a,c));
	}
}
void solve()
{
	int i,res(0),x(1);
	while(x)
	{
		if(S[x])
			res = max( res , dijkstra(x,S[x]) );
		x = S[x];
	}
	printf("%d\n",res);
}
int main()
{
	read();
	init_dijkstra();
	solve();
	return 0;
}
