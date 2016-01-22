#include <iostream>
#include <cstdio>
#include <cstring>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define TFOR(i,a,b) for(i=a; i>=b; i--)
#define MAXN 1005
using namespace std;
long long A[MAXN],B[MAXN];
long long T[MAXN][MAXN];
int K,N,R;
void rotate()
{
	int i;
	A[N+1] = A[1];
	FOR(i,1,N)
		A[i] = A[i+1];
}
long long solve()
{
	memset( B , 0 , sizeof B );
	long long res(0);
	int i,j,pos(1);
	scanf("%d %d %d",&R,&K,&N);
	FOR(i,1,N) scanf("%lld",A+i);
	FOR(i,1,N)
	{
		FOR(j,1,N)
		{
			T[i][j] = T[i][j-1] + A[j];
			if(T[i][j] > K && !B[i]) B[i] = j;
		}
		rotate();
	}
	if(T[1][N] <= K) return T[1][N] * R;
	FOR(i,1,R)
	{
		int t = B[pos];
		res += T[pos][t-1];
		pos += t - 1;
		if(pos > N) pos -= N;
	}
	return res;
}
int main()
{
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
	int T,i;
	scanf("%d",&T);
	FOR(i,1,T)
		printf("Case #%d: %lld\n",i,solve());
	getchar(); getchar();
	return 0;
}
