#include <iostream>
#include <algorithm>
#include <cstdio>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define TFOR(i,a,b) for(i=a; i>=b; i--)
#define f first
#define s second
#define MAXN 500000
using namespace std;
typedef pair < long long , long long > pll;
pll A[MAXN+5];
int N;
long long MINI[MAXN+5],RES[MAXN+5];
inline bool cmp( const pll &a , const pll &b ) { return a.s < b.s; }
void solve()
{
	register int i,j;
	register long long a,b,mini(2000000000),s(0);
	scanf("%d",&N);
	FOR(i,1,N)
		scanf("%lld %lld",&A[i].f,&A[i].s);
	sort(A+1,A+N+1,cmp);
	MINI[N] = A[N].f;
	TFOR(i,N-1,1) MINI[i] = min( MINI[i+1] , A[i].f );
	FOR(i,1,N)
	{
		if(A[i].f - A[i].s < mini) { mini = A[i].f - A[i].s; a = A[i].f; b = A[i].s; }
		printf("%lld\n",min( s + MINI[i] , a + s + A[i].s - b ) );
		s+=A[i].s;
	}
}
int main()
{
	solve();
	return 0;
}
