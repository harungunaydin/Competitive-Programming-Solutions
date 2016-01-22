#include <algorithm>
#include <cstdio>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define TFOR(i,a,b) for(i=a; i>=b; i--)
#define all(x) x.begin(),x.end()
#define MAXN 1005
using namespace std;
int M,N;
int A[MAXN][MAXN];
void solve()
{
	int i,j;
	char c;
	scanf("%d %d",&M,&N);
	FOR(i,1,M)
		FOR(j,1,N)
			scanf("%d",A[i]+j);

	if(N&1)
	{
		FOR(i,1,N)
		{
			c = (i&1) ? 'D' : 'U';
			FOR(j,1,M-1)
				printf("%c" , c );
			(i < N) ? printf("R") : printf("\n");
		}
	}
	else if(M&1)
	{
		FOR(i,1,M)
		{
			c = (i&1) ? 'R' : 'U';
			FOR(j,1,N-1)
				printf("%c" , c );
			(i < N) ? printf("D") : printf("\n");
		}
	}
	else
	{
		int mini(10000),t,x,y;
		FOR(i,1,M)
			FOR(j,1,N)
				if( ((i+j)&1) && A[i][j] < mini)
				{
					x = i;
					y = j;
					mini = A[i][j];
				}
		if((x&1) && !(y&1))
		{
			if(y == N)
			{
				FOR(i,1,N)
				{
					if(i == y-1)
					{
						FOR(i,1,x/2)
							printf("RDLD");
						printf("D");
						FOR(i,1,(M-x)/2)
							printf("RDLD");
						printf("R\n");
						return;
					}
					t = i&1;
					c = (t) ? 'D' : 'U';
					FOR(j,1,M-1)
						printf("%c" , c );
					printf("R");
				}
			}

			FOR(i,1,N)
			{
				if(i == y)
				{
					FOR(j,1,(M-x)/2)
						printf("RULU");
					if(x == 1)
					{
						printf("RUR");
						i++; continue;
					}
					printf("RUULU");
					FOR(j,1,x/2-1)
						printf("RULU");
					printf("RR");
					i++; continue;
				}
				t = i&1;
				if(i > y) t = !t;
				c = (t) ? 'D' : 'U';
				FOR(j,1,M-1)
					printf("%c" , c );
				(i < N) ? printf("R") : printf("\n");
			}
		}
		else if(!(x&1) && (y&1))
		{
			FOR(i,1,N)
			{
				if(i == y)
				{
					FOR(j,1,x/2-1)
						printf("RDLD");
					if(x == M)
					{
						printf("RDR");
						i++; continue;
					}
					printf("RDDLD");
					FOR(j,1,(M-x)/2-1)
						printf("RDLD");
					printf("R");
					i++;
					if(i != N) printf("R");
					continue;
				}
				t = i&1;
				if(i > y) t = !t;
				c = (t) ? 'D' : 'U';
				FOR(j,1,M-1)
					printf("%c" , c );
				(i < N) ? printf("R") : printf("\n");
			}
		}
	}

}
int main()
{
	solve();
	return 0;
}
