#include <iostream>
#include <queue>
#include <vector>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define EKLE(x,s) { qx.push(x); qs.push(s); visited[x]=true; }
#define BAK(x,s) { x=qx.front(); s=qs.front(); qx.pop(); qs.pop(); }
using namespace std;
queue <int> qx,qs;
vector <int> V[10005];
int M,N;
int A[1005][1005];
bool visited[1005];
void solve()
{
	int i,j,s,x;
	scanf("%d %d",&N,&M);
	FOR(i,1,N)
		FOR(j,1,N)
			scanf("%d",&A[i][j]);
	EKLE(M,0);
	while(!qx.empty())
	{
		BAK(x,s);
		V[s].push_back(x);
		FOR(i,1,N)
			if(A[x][i] && !visited[i])
				EKLE(i,s+1);
	}
	FOR(i,0,N*N-1)
		if(V[i].size())
		{
			sort(V[i].begin(),V[i].end());
			FOR(j,0,V[i].size()-1)
			{
				printf("%d",V[i][j]);
				if(j < V[i].size()-1) printf(" ");
			}
			printf("\n");
		}
}
int main()
{
	solve();
	return 0;
}
