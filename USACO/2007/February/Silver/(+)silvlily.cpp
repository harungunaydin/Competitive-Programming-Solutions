#include <iostream>
#include <cstdio>
#include <queue>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define f first
#define s second
#define mp(a,b) make_pair(a,b)
#define EKLE(x,y,z,a) pq.push(mp( mp(-(z),-(a)) , mp(x,y) ));
#define BAK(x,y,z,a) { x = pq.top().s.f; y = pq.top().s.s; z = - pq.top().f.f; a = -pq.top().f.s; pq.pop(); }
#define KONTROL(x,y) ( x >= 1 && x <= M && y >= 1 && y <= N && A[x][y] != 2)
#define INF 20000000
#define MAXN 31
using namespace std;
typedef pair < int , int > pii;
typedef pair < pii , pii > pii4;
priority_queue < pii4 > pq;
class lily
{
	public:
		int a,k,z;
		lily() { a = z = INF; k = 0; }
		void set(int zambak,int atlama,int kactane) { a = atlama; k = kactane; z = zambak;  }
}d[MAXN][MAXN];
int M,N,bx,by,hx,hy;
int yon[8][2] = { {2,1},{1,2},{-1,2},{-2,1},{-2,-1},{-1,-2},{1,-2},{2,-1} };
int A[MAXN][MAXN];

void BFS()
{
	int a,i,x,xx,y,yy,z;
	EKLE(bx,by,0,0);
	d[bx][by].set(0,0,1);
	while(!pq.empty())
	{
		BAK(x,y,z,a);
		FOR2(i,8)
		{
			xx = x + yon[i][0];
			yy = y + yon[i][1];
			if(!KONTROL(xx,yy)) continue;
			if(!A[xx][yy])
			{
				if(z + 1 < d[xx][yy].z)
				{
					d[xx][yy].set(z+1,a+1,d[x][y].k);
					EKLE(xx,yy,z+1,a+1);
				}
				else if(z + 1 == d[xx][yy].z)
				{
					if(a + 1 < d[xx][yy].a)
					{
						d[xx][yy].set(z+1,a+1,d[x][y].k);
						EKLE(xx,yy,z+1,a+1);
					}
					else if(a + 1 == d[xx][yy].a)
						d[xx][yy].k += d[x][y].k;
				}
			}
			else
			{
				if(z < d[xx][yy].z)
				{
					d[xx][yy].set(z,a+1,d[x][y].k);
					EKLE(xx,yy,z,a+1);
				}
				else if(z == d[xx][yy].z)
				{
					if(a + 1 < d[xx][yy].a)
					{
						d[xx][yy].set(z,a+1,d[x][y].k);
						EKLE(xx,yy,z,a+1);
					}
					else if(a + 1 == d[xx][yy].a)
						d[xx][yy].k += d[x][y].k;
				}
			}
		}
	}
	if(d[hx][hy].z > 900 || d[hx][hy].a > 900 || !d[hx][hy].k) printf("-1\n");
	else
		printf("%d\n%d\n%d\n" , d[hx][hy].z , d[hx][hy].a , d[hx][hy].k );
}
void solve()
{
	int i,j;
	scanf("%d %d",&M,&N);
	FOR(i,1,M)
		FOR(j,1,N)
		{
			scanf("%d",A[i]+j);
			if(A[i][j] == 3) { A[i][j] = 1; bx = i,by = j; }
			else if(A[i][j] == 4) { A[i][j] = 1; hx = i,hy = j; }
		}
	BFS();
}
int main()
{
	solve();
	return 0;
}
