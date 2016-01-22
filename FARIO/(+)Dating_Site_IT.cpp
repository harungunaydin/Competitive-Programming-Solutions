#include <iostream>
#include <cstdio>
#define FOR(i,a,b) for(i=a; i<=b; i++)
using namespace std;
int A[105][105][105];
int x1,x2,y1,y2,z1,z2;
void solve()
{
	register int M,N,i,j,k,res(0),t;
	scanf("%d %d",&M,&N);
	FOR(i,1,M)
	{
		scanf("%d %d %d %d %d %d",&x1,&x2,&y1,&y2,&z1,&z2);
		x1++; y1++; z1++; x2++; y2++; z2++;
		A[x1][y1][z1]++;
		A[x2+1][y1][z1]--;
		A[x1][y2+1][z1]--;
		A[x1][y1][z2+1]--;
		A[x2+1][y2+1][z1]++;
		A[x2+1][y1][z2+1]++;
		A[x1][y2+1][z2+1]++;
		A[x2+1][y2+1][z2+1]--;
	}
	FOR(i,1,100)
		FOR(j,1,100)
			FOR(k,1,100)
				A[i][j][k] += A[i-1][j][k] + A[i][j-1][k] + A[i][j][k-1]
								- A[i-1][j-1][k] - A[i-1][j][k-1] - A[i][j-1][k-1] + A[i-1][j-1][k-1];
	FOR(i,1,N)
	{
		scanf("%d %d %d %d",&x1,&y1,&z1,&t);
		x1++; y1++; z1++;
		if(!A[x1][y1][z1]) res += t;
	}
	printf("%d\n" , res );
}
int main()
{
	solve();
	return 0;
}
