#include <algorithm>
#include <cstdio>
#include <vector>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define TFOR(i,a,b) for(i=a; i>=b; i--)
#define MAX(a,b) ( (a) > (b) ? (a) : (b) )
#define f first
#define s second
#define MAXN 50001
#define MAXM 100001
using namespace std;
typedef pair < int , int > pii;
class Edge
{
	public:
		int a,b,c;
		void read() { scanf("%d %d %d",&a,&b,&c); }
}E[MAXM];
bool cmp( const Edge &a , const Edge &b ) { return a.c < b.c; }
vector < pii > G[MAXN];
int M,N,Q,maxi,vis;
int Dg[MAXN],ata[MAXN],visited[MAXN];
int MAX[MAXN][16] , next[MAXN][16];
int atabul(int x)
{
	if(ata[x] == x) return x;
	return ata[x] = atabul(ata[x]);
}
void Kruskal()
{
	int i;
	FOR(i,1,N) ata[i] = i;
	
	sort(E+1,E+M+1,cmp);

	FOR(i,1,M)
		if(atabul(E[i].a) != atabul(E[i].b) )
		{
			ata[atabul(E[i].a)] = atabul(E[i].b);
			G[E[i].a].push_back( make_pair(E[i].b,E[i].c) );
			G[E[i].b].push_back( make_pair(E[i].a,E[i].c) );
		}
}
void Generate(int x,int s)
{
	visited[x] = vis;
	Dg[x] = s;
	vector < pii > :: iterator it;
	for(it = G[x].begin(); it != G[x].end(); ++it)
		if(visited[it->f] != vis)
		{
			next[it->f][0] = x;
			MAX[it->f][0] = it->s;
			Generate(it->f,s+1);
		}
}
void Init()
{
	int i,j;
	FOR(j,1,15)
		FOR(i,1,N)
		{
			next[i][j] = next[ next[i][j-1] ][ j-1 ];
			MAX[i][j] = MAX( MAX[i][j-1] , MAX[ next[i][j-1] ][j-1] );
		}
}
int ilerle(int a,int k)
{
	for(int i = 0; k; k >>= 1,i++)
		if(k&1)
		{
			maxi = MAX( maxi , MAX[a][i] );
			a = next[a][i];
		}
	return a;
}
int LCA_bul_ve_ayar_cek(int a , int b)
{
	maxi = 0;
	if(Dg[a] > Dg[b]) a = ilerle(a,Dg[a] - Dg[b]);
	else if(Dg[b] > Dg[a]) b = ilerle(b,Dg[b] - Dg[a]);

	if(a == b) return maxi;
	
	for(int i = 15; i >= 0; i--)
		if( next[a][i] != next[b][i] )
		{
			maxi = MAX( maxi , MAX[a][i] );
			maxi = MAX( maxi , MAX[b][i] );
			a = next[a][i];
			b = next[b][i];
		}
	return MAX( maxi , MAX( MAX[a][0] , MAX[b][0]) );
}

void solve()
{
	int a,b,i;
	scanf("%d %d",&N,&M);

	FOR(i,1,M)
		E[i].read();

	FOR(i,1,N) G[i].clear();

	Kruskal();

	Generate(1,0);

	Init();

	scanf("%d",&Q);

	FOR(i,1,Q)
	{
		scanf("%d %d",&a,&b);
		printf("%d\n" , LCA_bul_ve_ayar_cek(a,b) );
	}
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		printf("Case %d:\n" , ++vis );
		solve();
	}
	return 0;
}
