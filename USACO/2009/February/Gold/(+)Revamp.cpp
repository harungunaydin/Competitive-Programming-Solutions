#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define f first
#define s second
#define EKLE(x,k,s) pq.push(make_pair(-(s),make_pair(x,k)))
#define BAK(x,k,s) { x = pq.top().s.f; k = pq.top().s.s; s = - pq.top().f; pq.pop(); }
#define MIN(a,b) ( (a) < (b) ? (a) : (b) )
#define MAXN 10001
using namespace std;
typedef pair < int , int > pii;
priority_queue < pair < int , pii > > pq;
vector < pii > G[MAXN];
int K,M,N;
int d[MAXN][21];
void solve()
{
	vector < pii > :: iterator it;
	int a,b,c,i,k,res(1231231231),s,x;
	scanf("%d %d %d",&N,&M,&K);
	FOR(i,1,M)
	{
		scanf("%d %d %d",&a,&b,&c);
		G[a].push_back(make_pair(b,c));
		G[b].push_back(make_pair(a,c));
	}
	memset( d , 127 , sizeof d );
	EKLE(1,K,0);
	while(!pq.empty())
	{
		BAK(x,k,s);
		if(x == N) { res = MIN( res , s ); continue; }
		for(it = G[x].begin(); it != G[x].end(); ++it)
		{
			if(s + it->s < d[it->f][k])
			{
				d[it->f][k] = s + it->s;
				EKLE(it->f,k,d[it->f][k]);
			}
			if(k && s < d[it->f][k-1])
			{
				d[it->f][k-1] = s;
				EKLE(it->f,k-1,s);
			}
		}
	}
	printf("%d\n" , res );
}
int main()
{
	solve();
	return 0;
}
