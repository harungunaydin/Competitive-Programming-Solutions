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
#define MAXN 1000
using namespace std;
typedef pair < int , int > pii;
priority_queue < pii > pq;
vector < pii > V[MAXN+5];
vector < int > G[MAXN+5];
int M,N,N2;
int d[MAXN+5];
void read()
{
	int a,b,c,i;
	scanf("%d %d",&N,&N2);
	scanf("%d",&M);
	FOR2(i,M)
	{
		scanf("%d %d",&a,&b);
		G[a].push_back(b);
	}
	scanf("%d",&M);
	FOR2(i,M)
	{
		scanf("%d %d %d",&a,&b,&c);
		V[a].push_back(make_pair(b,c));
	}
}
int solve()
{
	vector < pii > :: iterator it;
	vector < int > :: iterator it2;
	int i,res(3000),s,x;
	scanf("%d %d",&x,&s);
	FOR(i,1,N) d[i] = 3000;
	EKLE(x,s);
	d[x] = s;
	while(!pq.empty())
	{
		BAK(x,s);
		if(x <= N2) res = min( res , s );
		if(!res) return 0;
		for(it = V[x].begin(); it != V[x].end(); ++it)
			if(s >= it->s && s - it->s < d[it->f])
			{
				d[it->f] = s - it->s;
				EKLE(it->f,d[it->f]);
			}
		for(it2 = G[x].begin(); it2 != G[x].end(); ++it2)
			if(s < d[*it2])
			{
				d[*it2] = s;
				EKLE(*it2,s);
			}
	}
	return res;
}
int main()
{
	read();
	printf("%d\n" , solve() );
	return 0;
}
