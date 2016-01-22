#include <algorithm>
#include <cstdio>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define TFOR(i,a,b) for(i=a; i>=b; i--)
#define all(x) x.begin(),x.end()
#define MAXN 1005
using namespace std;
int N;
int A[MAXN];
void solve()
{
	int i,j,k(1),res(0);
	scanf("%d",&N);
	FOR(i,1,N)
		scanf("%d" , A+i );
	N++;
	FOR(i,1,N)
		if(A[i] <= A[i-1])
		{
			res = max( res , A[i-1] - A[k] );
			k = i;
		}

	printf("%d\n" , res );

}
int main()
{
	solve();
	return 0;
}
