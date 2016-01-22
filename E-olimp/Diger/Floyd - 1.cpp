#include <iostream>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define all(x) x.begin(),x.end()
#define MAXN 100
using namespace std;
int N;
int A[MAXN+5][MAXN+5];
void read()
{
	int i,j;
	scanf("%d",&N);
	FOR(i,1,N)
		FOR(j,1,N)
			scanf("%d",&A[i][j]);
}
void solve()
{
	int i,j,k;
	FOR(k,1,N)
		FOR(i,1,N)
			FOR(j,1,N)
				A[i][j] = min(A[i][j],A[i][k] + A[k][j]);
	for(i=1; i<=N; i++,printf("\n"))
		FOR(j,1,N)
		{
			printf("%d",A[i][j]);
			if(j!=N) printf(" ");
		}
}
int main()
{
	read();
	solve();
	return 0;
}
