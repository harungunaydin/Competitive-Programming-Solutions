#include <cstdio>
#include <cstring>
#include <queue>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define TFOR(i,a,b) for(i=a; i>=b; i--)
#define EKLE(x,y,s) { qx.push(x); qy.push(y); qs.push(s); visited[x][y] = vis; }
#define BAK(x,y,s)  { x = qx.front(); y = qy.front(); s = qs.front(); qx.pop(); qy.pop(); qs.pop(); }
#define KONTROL(x,y) ( 1 <= x && x <= M && 1 <= y && y <= N && A[x][y] != 'X' && A[x][y] != 'D' && visited[x][y] != vis )
#define all(x) x.begin(),x.end()
#define MAXN 55
using namespace std;
queue < int > qx,qy,qs;
int M,N,vis;
int yon[4][2] = { {1,0},{0,1},{-1,0},{0,-1} };
int S[MAXN][MAXN] , visited[MAXN][MAXN];
char A[MAXN][MAXN];
void hesapla(int x,int y)
{
	vis++;
	int i,s;
	EKLE(x,y,0);
	while(!qx.empty())
	{
		BAK(x,y,s);

		S[x][y] = min( S[x][y] , s );

		FOR2(i,4)
			if(KONTROL(x+yon[i][0],y+yon[i][1]))
				EKLE(x+yon[i][0],y+yon[i][1],s+1);
	}
}
void solve()
{
	memset( S , 31 , sizeof S );
	int bx,by,i,j,s,x,y;
	scanf("%d %d",&M,&N);
	FOR(i,1,M)
		FOR(j,1,N)
		{
			scanf(" %c" , A[i] + j );
			if( A[i][j] == 'S' ) bx = i , by = j;
			if( A[i][j] == 'D' ) S[i][j] = 1000000;
		}

	FOR(i,1,N)
		FOR(j,1,N)
			if(A[i][j] == '*')
				hesapla(i,j);

	EKLE(bx,by,0);

	vis++;

	while(!qx.empty())
	{
		BAK(x,y,s);

		if(A[x][y] == 'D') { printf("%d\n" , s ); return; }

		visited[x][y] = vis;

		FOR2(i,4)
		{
			int xx = x + yon[i][0];
			int yy = y + yon[i][1];
			if(xx < 1 || xx > M || yy < 1 || yy > N) continue;
			if(A[xx][yy] == 'X' || visited[xx][yy] == vis) continue;

			if( S[xx][yy] > s + 1 )
				EKLE(xx,yy,s+1);

		}
		
	}

	printf("KAKTUS\n");

}
int main()
{
	solve();
	return 0;
}
