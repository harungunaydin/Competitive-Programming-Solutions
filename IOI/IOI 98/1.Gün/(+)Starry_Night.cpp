#include <iostream>
#include <vector>
#include <queue>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define EKLE(x,y) { qx.push(x); qy.push(y); A[x][y] = '0'; }
#define BAK(x,y) { x = qx.front(); y = qy.front(); qx.pop(); qy.pop(); }
#define f first
#define s second
#define MAXN 100
#define all(x) x.begin(),x.end()
using namespace std;
typedef pair <int,int> pii;
vector <pii> V[502];
vector <int> D[502][162];
int M,N,S;
int yon[8][2] = { {1,0},{1,1},{0,1},{-1,1},{-1,0},{-1,-1},{0,-1},{1,-1} };
char A[MAXN+5][MAXN+5],res[MAXN+5][MAXN+5];
bool colored[100005];
int Distance(pii a,pii b)
{
	return (b.f-a.f)*(b.f-a.f) + (b.s-a.s)*(b.s-a.s);
}
void BFS(int x,int y)
{
	queue <int> qx,qy;
	int i;
	EKLE(x,y);
	S++;
	while(!qx.empty())
	{
		BAK(x,y);
		V[S].push_back(make_pair(x,y));
		FOR2(i,8)
			if(A[x+yon[i][0]][y+yon[i][1]] == '1')
				EKLE(x+yon[i][0],y+yon[i][1]);
	}
}
void BOYA(int a,char color)
{
	int i;
	colored[a] = true;
	FOR2(i,V[a].size())
		res[V[a][i].f][V[a][i].s] = color;
}
bool control(int a,int b)
{
	if(V[a].size() != V[b].size()) return 0;
	if(V[a].size() == 1) return 1;
	int i,j;
	FOR2(i,V[a].size())
		FOR2(j,D[a][i].size())
			if(D[a][i][j] != D[b][i][j])
				return 0;
	return 1;
}
void solve()
{
	int i,j,k;
	char color = 'a'-1;
	scanf("%d %d",&N,&M);
	FOR(i,1,M)
		FOR(j,1,N)
			scanf(" %c",A[i]+j);
	FOR(i,1,M)
		FOR(j,1,N)
			if(A[i][j] == '1')
				BFS(i,j);
	FOR(i,1,S)
	{
		FOR2(j,V[i].size())
		{
			FOR2(k,V[i].size())
				if(j != k)
					D[i][j].push_back(Distance(V[i][j],V[i][k]));
			sort(all(D[i][j]));
		}
		sort(D[i],D[i]+V[i].size());
	}
	FOR(i,1,S)
	{
		if(!colored[i])
			BOYA(i,++color);
		FOR(j,i+1,S)
			if(!colored[j] && control(i,j))
			{
				colored[j] = true;
				BOYA(j,color);
			}
	}
	for(i=1; i<=M; i++,printf("\n"))
		FOR(j,1,N)
			if(res[i][j])
				printf("%c",res[i][j]);
			else
				printf("0");
}
int main()
{
	solve();
	return 0;
}
