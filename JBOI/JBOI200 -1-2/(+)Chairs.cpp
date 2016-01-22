#include <iostream>
#include <cstdio>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
using namespace std;
int A[30][70][70],B[30][70][70];
void solve()
{
	int N,a1,a2,b1,b2,c1,c2,i,j,k,res(0),s(0);
	scanf("%d",&N);
	FOR(i,1,N)
	{
		scanf("%d:%d:%d",&a1,&b1,&c1);
		scanf("%d:%d:%d",&a2,&b2,&c2);
		A[a1][b1][c1]++;
		B[a2][b2][c2]++;
	}
	FOR2(i,24)
		FOR2(j,60)
			FOR2(k,60)
			{
				s+=A[i][j][k];
				res = max( res , s );
				s-=B[i][j][k];
			}
	printf("%d\n",res);
}
int main()
{
	solve();
	return 0;
}
