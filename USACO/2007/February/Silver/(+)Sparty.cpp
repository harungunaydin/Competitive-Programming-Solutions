#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define f first
#define s second
#define MAX(a,b) ( (a) > (b) ? (a) : (b)  )
#define EKLE(x,s) pq.push(make_pair(-(s),x))
#define BAK(x,s)  { x = pq.top().s; s = - pq.top().f; pq.pop(); }
#define MAXN 1001
using namespace std;
typedef pair < int , int > pii;
priority_queue < pii > pq;
vector < pii > G[MAXN];
int X,M,N;
int A[MAXN][MAXN];
void dijkstra(int a)
{
	vector < pii > :: iterator it;
	int s,x;
	A[a][a] = 0;
	EKLE(a,0);
	while(!pq.empty())
	{
		BAK(x,s);
		for(it = G[x].begin(); it != G[x].end(); ++it)
			if(s + it->s < A[a][it->f])
			{
				A[a][it->f] = s + it->s;
				EKLE(it->f,A[a][it->f]);
			}
	}
}
void solve()
{
	memset( A , 127 , sizeof A );
	int a,b,c,i,res(0);
	scanf("%d %d %d",&N,&M,&X);
	FOR(i,1,M)
	{
		scanf("%d %d %d",&a,&b,&c);
		G[a].push_back(make_pair(b,c));
	}
	FOR(i,1,N)
		dijkstra(i);
	FOR(i,1,N)
		res = MAX( res , A[i][X] + A[X][i] );
	printf("%d\n" , res );
}
int main()
{
	solve();
	return 0;
}
