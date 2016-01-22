#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define TFOR(i,a,b) for(i=a; i>=b; i--)
#define MAX(a,b) ( (a) > (b) ? (a) : (b) )
#define MIN(a,b) ( (a) < (b) ? (a) : (b) )
#define INF 2000000000
#define f first
#define s second
#define MAXN 100005
using namespace std;
typedef pair < int , int > pii;
int N,maxi,mini,vis;
int Dg[MAXN] , visited[MAXN];
int MAX[MAXN][18] , MIN[MAXN][18] , next[MAXN][18];
vector < pii > G[MAXN];
void dfs(int x,int s)
{
    visited[x] = vis;
    Dg[x] = s;
    vector < pii > :: iterator it;
    for(it = G[x].begin(); it != G[x].end(); ++it)
        if(visited[it->f] != vis)
        {
            next[it->f][0] = x;
            MAX[it->f][0] = MIN[it->f][0] = it->s;
            dfs(it->f,s+1);
        }
}
int ilerle(int a,int k)
{
	maxi = 0;
	mini = INF;
	register int i;
    for(i = 0; k; k >>= 1,i++)
      if(k&1)
		{
			maxi = MAX( maxi , MAX[a][i] );
			mini = MIN( mini , MIN[a][i] );
			a = next[a][i];
		}
    return a;
}
int LCA(int a,int b)
{
	if(Dg[a] > Dg[b] && ilerle(a,Dg[a]-Dg[b]) == b) return b;
	if(Dg[b] > Dg[a] && ilerle(b,Dg[b]-Dg[a]) == a) return a;
	if(Dg[a] < Dg[b]) b = ilerle(b,Dg[b] - Dg[a]);
  	if(Dg[a] > Dg[b]) a = ilerle(a,Dg[a] - Dg[b]);
	register int i;
  	TFOR(i,17,0)
	  if(next[a][i] != next[b][i])
	  {
			a = next[a][i];
			b = next[b][i];
      }
	return next[a][0];
}
void query(int a,int b)
{
    register int i,c = LCA(a,b) , resmax(0),resmin(INF);
    if(Dg[a] > Dg[c])
    {
    	ilerle(a,Dg[a] - Dg[c]);
    	resmax = maxi;
    	resmin = mini;
	}
    if(Dg[b] > Dg[c])
   	 	ilerle(b,Dg[b] - Dg[c]);
    printf("%d %d\n" , MIN( resmin , mini ) , MAX( resmax , maxi ) );
}
void solve()
{
	memset( MIN , 127 , sizeof MIN );
    register int Q,a,b,c,i,j;
    scanf("%d",&N);
    FOR(i,1,N) G[i].clear();
    FOR(i,1,N-1)
    {
        scanf("%d %d %d",&a,&b,&c);
        G[a].push_back(make_pair(b,c));
        G[b].push_back(make_pair(a,c));
    }
    dfs(1,1);
    FOR(j,1,17)
    	FOR(i,1,N)
    	{
    		next[i][j] = next[ next[i][j-1] ][ j-1 ];
    		MAX[i][j] = MAX( MAX[i][j-1] , MAX[ next[i][j-1] ][j-1] );
    		MIN[i][j] = MIN( MIN[i][j-1] , MIN[ next[i][j-1] ][j-1] );
		}
    scanf("%d",&Q);
    FOR(i,1,Q)
    {
        scanf("%d %d",&a,&b);
        query(a,b);
    }
}
int main()
{
    int T,i;
    scanf("%d",&T);
    FOR(i,1,T)
    {
		vis = i;
        printf("Case %d:\n",i);
        solve();
    }
    return 0;
}
