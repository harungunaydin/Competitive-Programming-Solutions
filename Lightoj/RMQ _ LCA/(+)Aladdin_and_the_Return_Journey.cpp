#include <cstdio>
#include <cstring>
#include <vector>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define MAXN 30002
#define MAXK 60002
using namespace std;
vector < int > G[MAXN];
int N,dis,vis;
int A[MAXN],Dg[MAXN],visited[MAXN];
int F[MAXN],S[MAXN],T[MAXN];
int BIT[MAXK];
int next[MAXN][15];
void dfs(int x,int s,int t)
{
	S[x] = ++dis;
	T[x] = t;
	Dg[x] = s;
	visited[x] = vis;
	vector < int > :: iterator it;
	for(it = G[x].begin(); it != G[x].end(); ++it)
		if(visited[*it] != vis)
		{
			next[*it][0] = x;
			dfs(*it,s+1,t+A[*it]);
		}
	F[x] = ++dis;
}
int ilerle(int a,int k)
{
	for(int i = 0; k; k >>= 1,i++)
		if(k&1)
			a = next[a][i];
	return a;
}
int LCA(int a,int b)
{
	if(Dg[a] > Dg[b]) a = ilerle(a,Dg[a] - Dg[b]);
	else if(Dg[a] < Dg[b]) b = ilerle(b,Dg[b] - Dg[a]);

	if(a == b) return a;
	
	for(int i = 14; i >= 0; i--)
		if(next[a][i] != next[b][i])
		{
			a = next[a][i];
			b = next[b][i];
		}

	return next[a][0];
}
void update(int a,int b,int v)
{
	int i;
	for(i = a; i <= dis; i += i&-i) BIT[i] += v;
	for(i = b + 1; i <= dis; i += i&-i) BIT[i] -= v;
}
int find(int i)
{
	int res(0);
	for(; i ; i -= i&-i)
		res += BIT[i];
	return res;
}
int _find(int a) { return T[a] + find(S[a]); }
int __find(int a,int b)
{
	int c = LCA(a,b);
	return _find(a) + _find(b) - _find(c) - _find(next[c][0]);
}
void _update(int k,int v)
{
	update(S[k],F[k],v - A[k]);
	A[k] = v;
}
void solve()
{
	int Q,a,b,i,j,k;
	scanf("%d",&N);
	FOR(i,1,N) scanf("%d",A+i);
	FOR(i,1,N) G[i].clear();
	vis++;
	dis = 0;
	memset( BIT , 0 , sizeof BIT );
	FOR(i,1,N-1)
	{
		scanf("%d %d",&a,&b);
		a++; b++;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	dfs(1,1,A[1]);

	FOR(j,1,14)
		FOR(i,1,N)
			next[i][j] = next[ next[i][j-1] ][ j-1 ];

	scanf("%d",&Q);
	FOR(i,1,Q)
	{
		scanf("%d %d %d",&k,&a,&b);
		if(k) _update(a+1,b);
		else printf("%d\n" , __find(a+1,b+1) );
	}
}
int main()
{
	int T,i;
	scanf("%d",&T);
	FOR(i,1,T)
	{
		printf("Case %d:\n",i);
		solve();
	}
	return 0;
}
