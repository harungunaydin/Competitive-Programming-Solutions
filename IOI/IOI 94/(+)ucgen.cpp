#include <iostream>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define TFOR(i,a,b) for(i=a; i>=b; i--)
#define MAXN 1000
using namespace std;
int A[MAXN+5][MAXN+5];
void solve()
{
	int N,i,j;
	scanf("%d",&N);
	FOR(i,1,N)
		FOR(j,1,i)
			scanf("%d",A[i]+j);
	TFOR(i,N-1,1)
		FOR(j,1,i)
			A[i][j]+=max(A[i+1][j],A[i+1][j+1]);
	printf("%d\n",A[1][1]);
}
int main()
{
	solve();
	return 0;
}
