#include <iostream>
#include <queue>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define EKLE(x,y,z) { qx.push(x); qy.push(y); qz.push(z); A[x][y][z]='.'; }
#define BAK(x,y,z)  { x=qx.front(); y=qy.front(); z=qz.front(); AL(); }
#define AL() { qx.pop(); qy.pop(); qz.pop(); }
#define KONTROL(x,y,z) (A[x][y][z]=='*')
using namespace std;
queue <int> qx,qy,qz;
int N;
int A[105][105][105],yon[6][3]={ {0,0,-1},{0,0,1},{0,1,0},{0,-1,0},{1,0,0},{-1,0,0} };
void read()
{
	int i,j,k;
	scanf("%d",&N);
	FOR(i,1,N)
		FOR(j,1,N)
			FOR(k,1,N)
				scanf(" %c",&A[i][j][k]);
}
void BFS(int a,int b,int c)
{
	int i,s,x,y,z;
	EKLE(a,b,c);
	while(!qx.empty())
	{
		BAK(x,y,z);
		FOR(i,0,5)
			if(KONTROL(x+yon[i][0],y+yon[i][1],z+yon[i][2]))
				EKLE(x+yon[i][0],y+yon[i][1],z+yon[i][2]);
	}
}
void solve()
{
	int i,j,k,s=0;
	FOR(i,1,N)
		FOR(j,1,N)
			FOR(k,1,N)
				if(A[i][j][k]=='*')
				{
					BFS(i,j,k);
					s++;
				}
	printf("%d\n",s);
}
int main()
{
	read();
	solve();
	return 0;
}
