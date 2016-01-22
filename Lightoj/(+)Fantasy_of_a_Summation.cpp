#include <cstdio>
#define FOR(i,a,b) for(i=a; i<=b; i++)
using namespace std;
int K,MOD,N,T;
int us(int b)
{
	if(!b) return 1;
	if(b == 1) return N;
	int t = us(b>>1);
	t = ( t * t ) % MOD;
	return b&1 ? ( N * t ) % MOD: t;
}
void solve()
{
	T = 0;
	int a,i;
	scanf("%d %d %d",&N,&K,&MOD);
	FOR(i,1,N)
	{
		scanf("%d",&a);
		a %= MOD;
		T = ( T + a ) % MOD;
	}
	N %= MOD;
	T = ( T * ( K % MOD ) ) % MOD;
	printf("%d\n" , ( us(K-1) * T ) % MOD );
}
int main()
{
	int T,i;
	scanf("%d",&T);
	FOR(i,1,T)
	{
		printf("Case %d: ",i);
		solve();
	}
	return 0;
}
