#include <algorithm>
#include <cstdio>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define TFOR(i,a,b) for(i=a; i>=b; i--)
#define all(x) x.begin(),x.end()
#define MAXN 105
using namespace std;
int N;
int A[MAXN];
void solve()
{
	int i,s(0);
	scanf("%d",&N);
	FOR(i,1,N)
		scanf("%d" , A+i );

	TFOR(i,N-1,1)
	{
		if(A[i] >= A[i+1])
		{
			s += A[i] - A[i+1] + 1;
			A[i] = A[i+1] - 1;
		}
	}

	printf("%d\n" , s );

}
int main()
{
	solve();
	return 0;
}
