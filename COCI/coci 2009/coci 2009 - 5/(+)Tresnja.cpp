#include <iostream>
#include <cstdio>
#include <cstring>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define TFOR(i,a,b) for(i=a; i>=b; i--)
using namespace std;
long long A,B;
long long us10[200];
long long DP[200][200];
inline long long f(long long t,long long k)
{
	return max ( 0LL , min( B , (t+1)*us10[k] - 1 ) - max( A , t*us10[k] )+1 );
}
long long dp(long long bas,long long pre,long long t)
{
	long long Max = (t+1) * us10[bas] - 1;
	long long Min = t * us10[bas];
	if(Min > B || Max < A) return 0;
	if(A <= Min && Max <= B && DP[bas][pre] != -1) return DP[bas][pre];
	long long i,j,k,res(0);
	FOR2(i,10)
		if(i != pre)
			for(j=1,k=t; j<=bas; j++)
			{
				k = k * 10 + i;
				res+=j*j*i*(f(k,bas-j)-f(k*10+i,bas-j-1))+dp(bas-j,i,k);
			}
	if(A <= Min && Max <= B) DP[bas][pre] = res;
	return res;
}
void solve()
{
	int i;
	scanf("%lld %lld",&A,&B);
	us10[0] = 1;
	FOR(i,1,16) us10[i] = us10[i-1] * 10;
	memset(DP,-1,sizeof DP);
	printf("%lld\n",dp(16,10,0));
}
int main()
{
	solve();
	return 0;
}
