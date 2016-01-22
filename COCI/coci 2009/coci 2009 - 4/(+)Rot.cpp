#include <iostream>
#include <vector>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define TFOR(i,a,b) for(i=a; i>=b; i--)
#define MAXN 10
using namespace std;
vector <int> V[1005];
int K,M,N;
char A[MAXN+5][MAXN+5],B[MAXN+5][MAXN+5];
void write(int a,char c)
{
	int i;
	FOR2(i,a)
		printf("%c",c);
}
void _90()
{
	int i,j;
	TFOR(i,M,1)
		FOR(j,1,N)
			B[j][M-i+1] = A[i][j];
	swap(M,N);
	FOR(i,1,M)
		FOR(j,1,N)
			A[i][j] = B[i][j];
}
void _45()
{
	int a,b,i;
	if(M <= N)
	{
		FOR(i,1,M)
		{
			a = i; b = 1;
			write(M-i,' ');
			while(a > 0)
			{
				printf("%c",A[a][b]);
				a--; b++;
				if(a) printf(" ");
			}
			printf("\n");
		}
	}
	if(M > N)
	{
		FOR(i,1,N)
		{
			a = i; b = 1;
			write(M-i,' ');
			while(a > 0)
			{
				printf("%c",A[a][b]);
				a--; b++;
				if(a) printf(" ");
			}
			printf("\n");
		}
		FOR(i,N+1,M)
		{
			a = i; b = 1;
			write(M-i,' ');
			while(b<=N)
			{
				printf("%c",A[a][b]);
				a--; b++;
				if(b<=N) printf(" ");
			}
			printf("\n");
		}
		FOR(i,2,N)
		{
			a = M; b = i;
			write(i-1,' ');
			while(b<=N)
			{
				printf("%c",A[a][b]);
				a--; b++;
				if(b<=N) printf(" ");
			}
			printf("\n");
		}
	}
	else
	{
		FOR(i,2,N)
		{
			a = M; b = i;
			write(i-1,' ');
			while(a && b<=N)
			{
				printf("%c",A[a][b]);
				a--; b++;
				if(a && b <= N) printf(" ");
			}
			printf("\n");
		}
	}
	exit(0);
}
void solve()
{
	int i,j;
	scanf("%d %d",&M,&N);
	FOR(i,1,M)
		FOR(j,1,N)
			scanf(" %c",A[i]+j);
	scanf("%d",&K);
	while(K>=90)
	{
		_90();
		K-=90;
	}
	if(K) _45();
	for(i=1; i<=M; i++,cout << endl)
		FOR(j,1,N)
			printf("%c",A[i][j]);
}
int main()
{
	solve();
	return 0;
}
