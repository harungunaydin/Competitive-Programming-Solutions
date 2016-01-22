#include <iostream>
#define FOR(i,a,b) for(i=a; i<=b; i++)
using namespace std;
int M,N;
int yon[4][2]={ {0,1},{1,0},{0,-1},{-1,0} };
bool A[105][105];
int kontrol(int x,int y)
{
	int i;
	FOR(i,0,3)
		if(!A[x+yon[i][0]][y+yon[i][1]])
			return 0;
	return 1;
}
int solve(int x,int y,int k)
{
	if(kontrol(x,y)) return 0;
	A[x][y]=true;
	if(!A[x+yon[k][0]][y+yon[k][1]]) return solve(x+yon[k][0],y+yon[k][1],k);
	return (!A[x+yon[(k+1)%4][0]][y+yon[(k+1)%4][1]])? solve(x+yon[(k+1)%4][0],y+yon[(k+1)%4][1],(k+1)%4)+1 : 0;
}
int main()
{
	cin >> M >> N;
	int i;
	A[M][0]=true;
	A[1][N+1]=true;
	A[M+1][N]=true;
	cout << solve(1,1,0) << endl;
	return 0;
}
