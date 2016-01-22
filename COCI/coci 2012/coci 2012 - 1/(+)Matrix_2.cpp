#include <iostream>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define all(x) x.begin(),x.end()
#define INF 2000000000
#define MAXN 400
using namespace std;
int N;
int A[MAXN+5][MAXN+5],B[MAXN+5][MAXN+5];
void solve()
{
	register int a,b,i,j,k,l,res(-INF),s;
	scanf("%d",&N);
	FOR(i,1,N)
		FOR(j,1,N)
		{
			scanf("%d",A[i]+j);
			B[i][j] = B[i-1][j+1] + A[i][j];
			A[i][j]+= A[i-1][j-1];
		}
	FOR(i,1,N)
		FOR(j,1,N)
			for(k=2; i+k-1<=N && j+k-1<=N; k++)
				res = max(res,(A[i+k-1][j+k-1] - A[i-1][j-1]) - (B[i+k-1][j] - B[i-1][j+k]));
	printf("%d\n",res);
}
int main()
{
	solve();
	return 0;
}
