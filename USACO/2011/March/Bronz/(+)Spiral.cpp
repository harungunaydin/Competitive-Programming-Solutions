#include <iostream>
using namespace std;
int N,s;
int A[800][800],yon[4][2]={ {0,1},{1,0},{0,-1},{-1,0} };
void print()
{
	int i,j;
	for(i=1; i<=N; i++,cout << endl)
		for(j=1; j<=N; j++)
		{
			printf("%d",A[i][j]);
			if(j < N) printf(" ");
		}
}
void solve(int x,int y,int k)
{
	A[x][y]=++s;
	if(s==N*N) { print(); exit(0); }
	if(A[x+yon[k][0]][y+yon[k][1]])
		solve(x+yon[(k+1)%4][0],y+yon[(k+1)%4][1],(k+1)%4);
	solve(x+yon[k][0],y+yon[k][1],k);
}
int main()
{
	scanf("%d",&N);
	A[1][N+1]=A[N+1][N]=A[N][0]=1;
	solve(1,1,0);
	return 0;
}
