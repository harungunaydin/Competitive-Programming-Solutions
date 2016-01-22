#include <algorithm>
#include <cstdio>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define TFOR(i,a,b) for(i=a; i>=b; i--)
#define all(x) x.begin(),x.end()
#define MAXN 55
using namespace std;
int M,N;
int B[300] , S[5];
char A[MAXN][MAXN];
void solve()
{
	int i,j;
	scanf("%d %d",&M,&N);
	FOR(i,1,M)
		scanf("%s" , A[i] + 1 );

	FOR(i,1,M-1)
		FOR(j,1,N-1)
		{
			B['X'] = B['.'] = B['#'] = 0;
			B[ A[i][j] ]++;
			B[ A[i][j+1] ]++;
			B[ A[i+1][j] ]++;
			B[ A[i+1][j+1] ]++;

			if(!B['#']) S[ B['X'] ]++;
		}

	FOR2(i,5)
		printf("%d\n" , S[i] );

}
int main()
{
	solve();
	return 0;
}
