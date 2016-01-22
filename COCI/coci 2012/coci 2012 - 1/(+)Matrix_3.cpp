#include <iostream>
#define FOR(i,a,b) for(i=a; i<=b; i++)
using namespace std;
int A[405][405],DP[405][405],DP2[405][405];
void solve()
{
	int N,i,j,k,maxi=0;
	scanf("%d",&N);
	FOR(i,1,N)
		FOR(j,1,N)
			scanf("%d",&A[i][j]);
	FOR(i,1,N)
		FOR(j,1,N)
			DP[i][j]=DP[i-1][j-1] + A[i][j];
	FOR(i,1,N)
		FOR(j,1,N)
			DP2[i][j]=DP2[i-1][j+1] + A[i][j];
	FOR(i,1,N-1)
		FOR(j,1,N-1)
			FOR(k,1,N-1)
				if(i + k <= N && j + k <= N)
					maxi=max(maxi,(DP[i+k][j+k] - DP[i-1][j-1]) - ( DP2[i+k][j] - DP2[i-1][j+k+1] ));
	printf("%d\n",maxi);
}
int main()
{
	solve();
	return 0;
}
