#include <algorithm>
#include <cstdio>
#include <queue>
#include <vector>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define TFOR(i,a,b) for(i=a; i>=b; i--)
#define EKLE(x,s) pq.push(make_pair(-(s),x))
#define BAK(x,s)  { x = pq.top().s; s = -pq.top().f; pq.pop(); }
#define f first
#define s second
#define pb push_back
#define all(x) x.begin(),x.end()
#define MAXN 105
using namespace std;
typedef pair < int , int > pii;
int read(){ int res(0),sign(1); char c;
	while(1){ c = getchar(); if('0' <= c && c <= '9') { res = c - '0'; break; } else if(c == '-') { sign = -1; break; } }
	while(1){ c = getchar(); if('0' <= c && c <= '9') res = res*10 + c - '0'; else break; }
	return res * sign;
}
priority_queue < pii > pq;
vector < pii > G[MAXN];
vector < int > V[MAXN][MAXN];
int K,M,N;
void solve()
{
	int a,b,c,i,s,x;
	N = read(); M = read();
	FOR(i,1,M)
	{
		a = read(); b = read(); c = read();
		G[a].push_back( make_pair(b,c) );
	}

	K = read();
	
	vector < pii > :: iterator it;

	FOR(i,1,N)
	{
		while(!pq.empty()) pq.pop();
		EKLE(i,0);
		while(!pq.empty())
		{
			BAK(x,s);

			if(i != x || s)
				V[i][x].push_back(s);

			for(it = G[x].begin(); it != G[x].end(); ++it)
				if(V[i][it->f].size() < 100)
					EKLE(it->f,s+it->s);

		}
	}

	while(K--)
	{
		a = read(); b = read(); c = read();

		if(V[a][b].size() < c) printf("-1\n");
		else printf("%d\n" , V[a][b][c-1] );

	}

}
int main()
{
	solve();
	return 0;
}
