#include <iostream>
#include <fstream>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define INFINITY INT_MAX/2
//#define cin in
using namespace std;
ifstream in("teleport.in");
int E,M,N;
int A[5005][5005],B[5005][4];
void solve()
{
	int a,b,c,i,j,k,x,y;
	cin >> N >> E;
	FOR(i,1,N)
		FOR(j,1,N)
			A[i][j]=INFINITY;
	FOR(i,1,N) A[i][i]=0;
	FOR(i,1,E)
	{
		cin >> x >> y >> c;
		A[x][y]=A[y][x]=c;
	}
	cin >> M;
	FOR(k,1,N)
		FOR(i,1,N)
			FOR(j,1,N)
				A[i][j]=min(A[i][j],A[i][k]+A[k][j]);
	FOR(i,1,M)
		cin >> B[i][1] >> B[i][2] >> B[i][3];
	FOR(i,1,N)
		FOR(j,i+1,N)
		{
			if(i==j) continue;
			FOR(k,1,M)
			{
				a=B[k][1];
				b=B[k][2];
				c=B[k][3];
				if(A[a][i]+A[j][b]<c || A[a][j]+A[i][b]<c)
					break;
				if(A[a][i]+A[j][b]>c && A[a][j]+A[i][b]>c && A[a][b]!=c)
					break;
			}
			if(k==M+1)
			{
				cout << i << " " << j << endl;
				return;
			}
		}
}
int main()
{
	solve();
	return 0;
}
