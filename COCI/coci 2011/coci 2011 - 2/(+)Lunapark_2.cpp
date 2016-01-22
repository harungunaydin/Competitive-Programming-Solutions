#include <iostream>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define all(x) x.begin(),x.end()
#define INF 2000000000
#define MAXN 1000
using namespace std;
string res,temp;
int M,N,maxi;
int yon2[5] = { 1,0,1 };
char K[5] = { 'D','R','U' };
int yon[4][2] = { {1,0},{0,1},{-1,0},{0,-1} };
int A[MAXN+5][MAXN+5];
void read()
{
	int i,j;
	scanf("%d %d",&M,&N);
	FOR(i,1,M)
		FOR(j,1,N)
			scanf("%d",A[i]+j);
}
void write(int x,int c)
{
	int i;
	FOR2(i,x)
		printf("%c",c);
}
void solve()
{
	int a(1),b(2),c,i,j,k(0),mini(INF),x,y;
	FOR(i,1,M)
		FOR(j,1,N)
			if((i+j)&1 && A[i][j] < mini)
			{
				mini = A[i][j];
				a = i,b = j;
			}
	c = a - 2 + (a&1);
	FOR(i,1,c)
	{
		write(N-1,(i&1) ? 'R' : 'L');
		printf("D");
	}
	x = c+1; y = 1;
	int z = 1;
	while(x < c+2 || y < N)
	{
		if(x+yon[k][0] == a && y+yon[k][1] == b) k = yon2[k];
		x+=yon[k][0]; y+=yon[k][1];
		z = (!k) ? 1 : (k == 2) ? -1 : z;
		printf("%c",K[k]);
		k+=z;
	}
	FOR(i,c+3,M)
	{
		printf("D");
		write(N-1,(i&1) ? 'L' : 'R');
	}
	printf("\n");
}
int main()
{
	read();
	int i,j;
	if(N&1)
		FOR(i,1,N)
		{
			write(M-1,(i&1) ? 'D' : 'U');
			if(i!=N) printf("R");
		}
	else if(M&1)
		FOR(i,1,M)
		{
			write(N-1,(i&1) ? 'R' : 'L');
			if(i!=M) printf("D");
		}
	else
		solve();
	return 0;
}
