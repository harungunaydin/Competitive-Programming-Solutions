#include <iostream>
#include <cstdio>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define MAXN 405
using namespace std;
int D,F,N;
int visited[MAXN];
bool A[MAXN][MAXN];
int dfs(int x,int vis)
{
	if(x == 401) return true;
	visited[x] = vis;
	int i;
	FOR(i,0,401)
		if(A[x][i] && visited[i] != vis && dfs(i,vis))
		{
			A[x][i] = false;
			A[i][x] = true;
			return true;
		}
	return false;
}
void solve()
{
	int a,d,f,i,j;
	scanf("%d %d %d",&N,&F,&D);
	FOR(i,1,N)
	{
		scanf("%d %d",&f,&d);
		FOR(j,1,f)
		{
			scanf("%d",&a);
			A[a][100+i] = true;
		}
		FOR(j,1,d)
		{
			scanf("%d",&a);
			A[200+i][300+a] = true;
		}
	}
	FOR(i,1,100) A[0][i] = true;
	FOR(i,101,200) A[i][100+i] = true;
	FOR(i,301,400) A[i][401] = true;
	int res(0),vis(0);
	while(dfs(0,++vis)) res++;
	printf("%d\n" , res );
}
int main()
{
	solve();
	return 0;
}
