#include <iostream>
#include <cmath>
#include <cstdio>
#include <queue>
#include <vector>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define f first
#define s second
#define EKLE(x,y,s) { qx.push(x); qy.push(y); qs.push(s); visited[x][y] = true; }
#define BAK(x,y,s) {  x = qx.front(); y  = qy.front(); s = qs.front(); qx.pop(); qy.pop(); qs.pop(); }
#define EKLE_PQ(x,y,s) pq.push(make_pair(s,make_pair(x,y)))
#define BAK_PQ(x,y,s) { x = pq.top().second.first; y = pq.top().second.second; s = pq.top().first; pq.pop(); }
#define KONTROL(x,y) (A[x][y] && !visited[x][y])
#define INF 2000000000
#define MAXN 500
using namespace std;
typedef pair < int , int > pii;
priority_queue < pair < int , pii > > pq;
queue < int > qx,qy,qs;
vector < pii > V;
vector < pii > :: iterator it;
int M,N;
int T[MAXN+5][MAXN+5],d[MAXN+5][MAXN+5];
int yon[4][2] = { {1,0},{0,1},{-1,0},{0,-1} };
char A[MAXN+5][MAXN+5];
bool visited[MAXN+5][MAXN+5];
void init()
{
	int i,x,y,s;
	while(!qx.empty())
	{
		BAK(x,y,s);
		T[x][y] = s;
		FOR2(i,4)
			if(KONTROL(x+yon[i][0],y+yon[i][1]))
				EKLE(x+yon[i][0],y+yon[i][1],s+1);
	}
}
void solve()
{
	int i,j,hx,hy,s,x,xx,y,yy;
	scanf("%d %d",&M,&N);
	FOR(i,1,M)
		FOR(j,1,N)
		{
			scanf(" %c",A[i]+j);
			if(A[i][j] == 'V')
				x = i,y = j;
			if(A[i][j] == '+')
				EKLE(i,j,0);
			if(A[i][j] == 'J')
				hx = i,hy = j;
		}
	init();
	EKLE_PQ(x,y,T[x][y]);
	d[x][y] = T[x][y];
	while(!pq.empty())
	{
		BAK_PQ(x,y,s);
		FOR2(i,4)
		{
			xx = x + yon[i][0];
			yy = y + yon[i][1];
			if(A[xx][yy] && min(s , T[xx][yy]) > d[xx][yy])
			{
				d[xx][yy] = min(s , T[xx][yy]);
				EKLE_PQ(xx,yy,d[xx][yy]);
			}
		}
	}
	printf("%d\n",d[hx][hy]);
}
int main()
{
	solve();
	return 0;
}
