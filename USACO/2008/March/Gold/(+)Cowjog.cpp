#include <iostream>
#include <cstdio>
#include <queue>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define f first
#define s second
#define EKLE(x,s) pq.push(make_pair(-(s),x))
#define BAK(x,s) { x = pq.top().s; s = - pq.top().f; pq.pop(); }
#define MAXN 1001
using namespace std;
typedef pair < int , int > pii;
priority_queue < pii > pq;
vector < pii > G[MAXN];
int K,M,N,t;
int RES[MAXN];
void solve()
{
	vector < pii > :: iterator it;
	int a,b,c,i,s,x;
	scanf("%d %d %d",&N,&M,&K);
	FOR(i,1,M)
	{
		scanf("%d %d %d",&a,&b,&c);
		G[a].push_back(make_pair(b,c));
	}
	EKLE(N,0);
	while(!pq.empty())
	{
		BAK(x,s);
		if(x == 1) { RES[++t] = s; if(t == K) break; continue; }
		for(it = G[x].begin(); it != G[x].end(); ++it)
			EKLE(it->f,s+it->s);
	}
	FOR(i,1,K)
		printf("%d\n" , RES[i] ? RES[i] : -1 );
}
int main()
{
	solve();
	return 0;
}
