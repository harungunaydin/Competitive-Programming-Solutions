#include <iostream>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define TFOR(i,a,b) for(i=a; i>=b; i--)
#define all(x) x.begin(),x.end()
#define INF 200000000
#define MAXN 300000
using namespace std;
long long A[MAXN+5];
long long LMAX[MAXN+5];
long long RMAX[MAXN+5];
long long LMIN[MAXN+5];
long long RMIN[MAXN+5];
long long sta[MAXN+5];
void solve()
{
	long long MAX(0),MIN(0),i;
	int N,bas(0);
	scanf("%d",&N);
	FOR(i,1,N)
		scanf("%lld",A+i);
	A[N+1] = INF;
	FOR(i,1,N+1)
	{
		while(bas>=0 && A[sta[bas]] <= A[i]) RMAX[sta[bas--]] = i;
		sta[++bas] = i;
	}
	bas = 0;
	A[N+1] = -INF;
	FOR(i,1,N+1)
	{
		while(bas>=0 && A[sta[bas]] > A[i]) RMIN[sta[bas--]] = i;
		sta[++bas] = i;
	}
	bas = 0;
	TFOR(i,N,1)
	{
		while(bas>=0 && A[sta[bas]] >= A[i]) LMIN[sta[bas--]] = i;
		sta[++bas] = i;
	}
	bas = 0;
	TFOR(i,N,1)
	{
		while(bas>=0 && A[sta[bas]] < A[i]) LMAX[sta[bas--]] = i;
		sta[++bas] = i;
	}
	FOR(i,1,N)
		MAX+=A[i]*(RMAX[i]-i)*(i-LMAX[i]);
	FOR(i,1,N)
		MIN+=A[i]*(RMIN[i]-i)*(i-LMIN[i]);
	printf("%lld\n",MAX - MIN);
}
int main()
{
	solve();
	return 0;
}
