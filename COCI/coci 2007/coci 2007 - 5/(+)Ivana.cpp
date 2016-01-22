#include <algorithm>
#include <cstdio>
#include <cstring>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define TFOR(i,a,b) for(i=a; i>=b; i--)
#define H(a,b) ( T[b] - T[a-1] )
#define all(x) x.begin(),x.end()
#define MAXN 205
using namespace std;
int N;
int A[MAXN] , T[MAXN];
int DP[MAXN][MAXN];
int dp(int a,int b)
{
	int &ret = DP[a][b];

	if(ret != -1) return ret;

	if(a == b) return ret = (A[a]&1);

	return ret = T[b] - T[a-1] - min( dp(a+1,b) , dp(a,b-1) );

}
void solve()
{
	memset( DP , -1 , sizeof DP );
	int i,res(0),t;
	scanf("%d",&N);
	FOR(i,1,N)
		scanf("%d",A+i);

	FOR(i,N+1,2*N)
		A[i] = A[i-N];

	FOR(i,1,2*N)
		T[i] = T[i-1] + (A[i]&1);

	FOR(i,1,N)
	{
		t = T[N] - dp(i+1,i+N-1);
		if(t > T[N] - t)
			res++;
	}
	
	printf("%d\n" , res );

}
int main()
{
	solve();
	return 0;
}
