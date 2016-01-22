#include <algorithm>
#include <cstdio>
#include <queue>
#include <vector>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define TFOR(i,a,b) for(i=a; i>=b; i--)
#define EKLE(x,s) { qx.push(x); qs.push(s); visited[x][s] = true; }
#define BAK(x,s)  { x = qx.front(); s = qs.front(); qx.pop(); qs.pop(); }
#define f first
#define s second
#define pb push_back
#define all(x) x.begin(),x.end()
#define MAXN 1005
#define MAXS 2005
using namespace std;
typedef pair < int , int > pii;
int read(){ int res(0),sign(1); char c;
	while(1){ c = getchar(); if('0' <= c && c <= '9') { res = c - '0'; break; } else if(c == '-') { sign = -1; break; } }
	while(1){ c = getchar(); if('0' <= c && c <= '9') res = res*10 + c - '0'; else break; }
	return res * sign;
}
vector < pii > G[MAXN];
int N,N2;
bool visited[MAXN][MAXS];
void BFS()
{
	queue < int > qs,qx;
	vector < pii > :: iterator it;
	int res(2005),s,x;
	x = read(); s = read();
	EKLE(x,s);
	while(!qx.empty())
	{
		BAK(x,s);
		
		if(x <= N2)
			res = min( res , s );

		for(it = G[x].begin(); it != G[x].end(); ++it)
			if(s >= it->s && !visited[it->f][s-it->s])
				EKLE(it->f,s-it->s);
	}

	printf("%d\n" , res );

}
void solve()
{
	int M,a,b;
	N = read(); N2 = read();
	M = read();
	while(M--)
	{
		a = read(); b = read();
		G[a].pb( make_pair(b,0) );
	}
	M = read();
	while(M--)
	{
		a = read(); b = read();
		G[a].pb( make_pair(b,read()) );
	}

	BFS();

}
int main()
{
	solve();
	return 0;
}
