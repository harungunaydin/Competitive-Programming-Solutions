#include <algorithm>
#include <cstdio>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define TFOR(i,a,b) for(i=a; i>=b; i--)
#define MAXN 300005
using namespace std;
int N;
int A[MAXN] , sta[MAXN];
int LMAX[MAXN] , LMIN[MAXN] , RMAX[MAXN] , RMIN[MAXN];
void solve()
{
	int bas,i;
	scanf("%d",&N);
	FOR(i,1,N)
		scanf("%d",A+i);

	bas = 0;
	FOR(i,1,N)
	{
		while(bas > 0 && A[ sta[bas] ] <= A[i] ) bas--;
		LMAX[i] = sta[bas];
		sta[++bas] = i;
	}

	bas = 0;
	FOR(i,1,N)
	{
		while(bas > 0 && A[ sta[bas]] >= A[i]) bas--;
		LMIN[i] = sta[bas];
		sta[++bas] = i;
	}

	bas = 0;
	TFOR(i,N,1)
	{
		while(bas > 0 && A[ sta[bas] ] < A[i]) bas--;
		RMAX[i] = (sta[bas]) ? sta[bas] : N + 1;
		sta[++bas] = i;
	}

	bas = 0;
	TFOR(i,N,1)
	{
		while(bas > 0 && A[ sta[bas] ] > A[i]) bas--;
		RMIN[i] = (sta[bas]) ? sta[bas] : N + 1;
		sta[++bas] = i;
	}

	long long mini(0) , maxi(0);
	FOR(i,1,N)
	{
		mini += (long long)(i - LMIN[i]) * (long long)(RMIN[i] - i) * A[i];
		maxi += (long long)(i - LMAX[i]) * (long long)(RMAX[i] - i) * A[i];
	}
	printf("%lld\n" , maxi - mini );

}
int main()
{
	solve();
	return 0;
}
