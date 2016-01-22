#include <iostream>
#include <queue>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define EKLE(x,y) { qx.push(x); qy.push(y); A[x][y]='.'; }
#define BAK(x,y) { x=qx.front(); y=qy.front(); qx.pop(); qy.pop(); }
#define KONTROL(x,y) (x>=1 && x<=N && y>=1 && y<=N && A[x][y]=='*')
using namespace std;
queue <int> qx,qy;
int N,s;
char A[1005][1005];
int yon[4][2]={ {1,0},{0,1},{-1,0},{0,-1} };
void BFS(int a,int b)
{
	int i,x,y;
	EKLE(a,b);
	while(!qx.empty())
	{
		BAK(x,y);
		FOR(i,0,3)
			if(KONTROL(x+yon[i][0],y+yon[i][1]))
				EKLE(x+yon[i][0],y+yon[i][1]);
	}
}
void solve()
{
	int i,j,x,y;
	scanf("%d",&N);
	FOR(i,1,N)
		FOR(j,1,N)
			scanf(" %c",&A[i][j]);
	FOR(i,1,N)
		FOR(j,1,N)
			if(A[i][j]=='*')
			{
				BFS(i,j);
				s++;
			}
	printf("%d\n",s);
}
int main()
{
	solve();
	return 0;
}
