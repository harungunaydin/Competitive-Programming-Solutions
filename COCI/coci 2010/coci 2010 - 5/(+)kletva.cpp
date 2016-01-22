#include <algorithm>
#include <cstdio>
#include <set>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define TFOR(i,a,b) for(i=a; i>=b; i--)
#define all(x) x.begin(),x.end()
#define BASE 100009ll
#define MAXN 1005
using namespace std;
set < long long > st;
int K,M,N;
long long A[MAXN];
long long hash()
{
	long long t(0);
	int i;
	FOR(i,1,N)
		t = t * BASE + A[i] - '0';
	return t;
}

void solve()
{
	long long a;
	int i,j;
	scanf("%d %d %d",&M,&N,&K);

	FOR(i,1,K)
	{
		FOR(j,1,N) scanf("%lld" , A+j );
		FOR(j,1,N) { scanf("%lld",&a); A[j] = M - (A[j] + a); }

		st.insert( hash() );
	}

	printf("%d\n" , (int) st.size() );

}
int main()
{
	solve();
	return 0;
}
