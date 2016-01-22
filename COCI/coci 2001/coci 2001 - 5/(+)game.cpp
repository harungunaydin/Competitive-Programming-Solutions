#include <iostream>
#define max(a,b,c) max(a,max(b,c))
#define ekle(c) ((c=='H')? 2 : (c=='F')? 6 : (c=='I')? 10 : 0 )
#define FOR(i,a,b) for(i=a; i<=b; i++)
using namespace std;
int M,N;
char A[105][105];
int game[105][105];
void read()
{
	int i,j;
	cin >> M >> N;
	FOR(i,1,M)
		FOR(j,1,N)
			cin >> A[i][j];
	game[M][N]=-1;
	for(i=1;i<=M;i++)
		A[i][N+1]='#';
	
	for(i=1;i<=N;i++)
		A[M+1][i]='#';
}
void solve()
{
	int a,b,c,i,j;
	for(i=M; i; i--)
		for(j=N; j; j--)
		{
			a=b=c=-123123;
			if((i==M && j==N) || A[i][j]=='#')
				continue;
			if(A[i+1][j+1]=='#' && A[i+1][j]==A[i+1][j+1] && A[i][j+1]==A[i+1][j]) { game[i][j]=-1; continue; }
			if(A[i+1][j+1]!='#') a=-game[i+1][j+1]+ekle(A[i+1][j+1]);
			if(A[i+1][j]!='#') b=-game[i+1][j]+ekle(A[i+1][j]);
			if(A[i][j+1]!='#') c=-game[i][j+1]+ekle(A[i][j+1]);
			game[i][j]=max(a,b,c);
		}
	int x,y;
	cin >> N;
	
	for(int i=0; i<N; i++)
	{
		cin >> x >> y;
		(game[x][y]>=0)? cout << "HAL" << endl : cout << "DAVE" << endl;
	}
}
int main()
{
	read();
	solve();
	//system("PAUSE");
	return 0;
}
