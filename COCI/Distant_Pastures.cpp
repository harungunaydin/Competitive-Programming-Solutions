#include <iostream>
#include <cstdio>
#include <queue>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define KONTROL(x,y) ( C[x][y])
#define EKLE(x,y,s) pq.push(make_pair(-(s),make_pair(x,y)))
#define BAK(x,y,s) { s = - pq.top().first; x = pq.top().second.first; y = pq.top().second.second; pq.pop(); }
#define MAXN 30
using namespace std;
FILE *in,*out;
priority_queue < pair < int , pair < int , int > > > pq;
int A,B,N,res,vis;
int visited[MAXN+5][MAXN+5],yon[4][2] = { {1,0},{0,1},{-1,0},{0,-1} };
char C[MAXN+5][MAXN+5];
inline void BFS(int x,int y)
{
	int i,s,ss,xx,yy;
	EKLE(x,y,0);
	vis++;
	while(!pq.empty())
	{
		BAK(x,y,s);
		if(visited[x][y] == vis) continue;
		visited[x][y] = vis;
		res = max( res , s );
		FOR2(i,4)
		{
			xx = x + yon[i][0];
			yy = y + yon[i][1];
			ss = s + ((C[xx][yy] == C[x][y]) ? A : B );
			if(KONTROL(xx,yy))
				EKLE(xx,yy,ss);
		}
	}
}
void solve()
{
	int i,j;
	fscanf(in,"%d %d %d",&N,&A,&B);
	FOR(i,1,N)
		FOR(j,1,N)
			fscanf(in," %c",C[i]+j);
	FOR(i,1,N)
		FOR(j,1,N)
			BFS(i,j);
	fprintf(out,"%d\n",res);
}
int main()
{
	in = fopen("distant.in","r");
	out = fopen("distant.out","w");
	solve();
	return 0;
}
