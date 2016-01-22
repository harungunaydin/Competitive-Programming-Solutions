#include <algorithm>
#include <cstdio>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define TFOR(i,a,b) for(i=a; i>=b; i--)
#define all(x) x.begin(),x.end()
#define MAXN 100005
using namespace std;
int A[MAXN] , DP[MAXN];
int solve()
{
	int N,i;

	scanf("%d",&N);
	FOR(i,1,N)
		scanf("%d" , A+i );

	if(N < 3) return A[N];

	DP[N] = A[N] + A[1] + A[2];

	DP[N-1] = min( DP[N] + A[1] + A[N-1] , A[2] + A[1] + A[N] + A[2] + A[2] );

	TFOR(i,N-2,3)
		DP[i] = min( DP[i+1] + A[1] + A[i] , DP[i+2] + A[i+1] + A[1] + 2*A[2] );

	return DP[3];

}
int main()
{
	printf("%d\n" , solve() );
	return 0;
}
