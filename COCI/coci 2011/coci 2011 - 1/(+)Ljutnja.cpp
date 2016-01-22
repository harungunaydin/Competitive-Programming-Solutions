#include <algorithm>
#include <cstdio>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define TFOR(i,a,b) for(i=a; i>=b; i--)
#define all(x) x.begin(),x.end()
#define MAXN 100005
using namespace std;
long long M,N;
long long A[MAXN];
void solve()
{
	long long i,res(0),t;
	scanf("%lld %lld",&M,&N);
	FOR(i,1,N)
		scanf("%lld",A+i);
	
	A[++N] = 0;

	sort( A+1 , A+N+1 );

	TFOR(i,N-1,1)
	{
		t = A[i+1] - A[i];
		if(M < t * ( N - i ) )
		{
			long long a = M / (N - i);
			long long b = M % (N - i);
			long long c = A[i+1] - a;

			res += b * (c-1) * (c-1) + (N - i - b) * c * c;

			break;
		}
		M -= t * (N - i);
	}
	for(; i >= 1; i--)
		res += A[i] * A[i];

	printf("%lld\n" , res );
}
int main()
{
	solve();
	return 0;
}
