#include <iostream>
#include <cstdio>
#include <cstring>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define TFOR(i,a,b) for(i=a; i>=b; i--)
#define KONTROL(x,y) ( x >= 1 && x <= M && y >= 1 && y <= N )
#define MAXN 105
using namespace std;
typedef pair < int , int > pii;
inline int Min( int a , int b ) { return a < b ? a : b; }
pii B[MAXN][MAXN];
int M,N;
int A[MAXN][MAXN],C[MAXN][MAXN],yon[4][2] = { {-1,0},{0,-1},{0,1},{1,0} };
void solve()
{
	memset( C , 0 , sizeof C );
	int i,j,k,mini,x,y;
	scanf("%d %d",&M,&N);
	FOR(i,1,M)
		FOR(j,1,N)
			scanf("%d",A[i]+j);
	FOR(i,1,M)
		FOR(j,1,N)
		{
			x = i; y = j;
			while(1)
			{
				mini = 10000;
				FOR2(k,4)
					if(KONTROL(x+yon[k][0],y+yon[k][1]))
						mini = Min( mini , A[x+yon[k][0]][y+yon[k][1]] );
				if(mini >= A[x][y])
				{
					B[i][j] = make_pair(x,y);
					break;
				}
				FOR2(k,4)
					if(KONTROL(x+yon[k][0],y+yon[k][1]) && A[x+yon[k][0]][y+yon[k][1]] == mini)
					{
						x += yon[k][0];
						y += yon[k][1];
						break;
					}
			}
		}
		char c = 'a' - 1;
		FOR(i,1,M)
			FOR(j,1,N)
			{
				x = B[i][j].first;
				y = B[i][j].second;
				if(C[x][y])
					C[i][j] = C[x][y];
				else
					C[i][j] = C[x][y] = ++c;
			}
		FOR(i,1,M)
			FOR(j,1,N)
				printf("%c%c",C[i][j],(j == N) ? '\n' : ' ');
}
int main()
{
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
	int T,i;
	scanf("%d",&T);
	FOR(i,1,T)
	{
		printf("Case #%d:\n",i);
		solve();
	}
	return 0;
}
