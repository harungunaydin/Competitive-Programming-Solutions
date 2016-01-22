#include <algorithm>
#include <cstdio>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define TFOR(i,a,b) for(i=a; i>=b; i--)
#define all(x) x.begin(),x.end()
#define MAXN 105
using namespace std;
double A[MAXN];
void solve()
{
	double b,res(0);
	int K,M,N,a,i;
	scanf("%d %d %d",&N,&M,&K);
	FOR(i,1,M*N)
	{
		scanf("%d %lf",&a,&b);
		A[a] = max( A[a] , b );
	}
	sort(A+1,A+N+1);
	TFOR(i,N,N-K+1)
		res += A[i];
	printf("%.1lf\n" , res );
}
int main()
{
	solve();
	return 0;
}
