#include <iostream>
#include <cmath>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define all(x) x.begin(),x.end()
#define MAXN 1000
#define MOD 1000000000
using namespace std;
long long gcd(long long a,long long b)
{
	return !b ? a : gcd(b,a%b);
}
long long A[MAXN+5],B[MAXN+5];
void solve()
{
	long long M,N,i,j,k,res(1);
	bool flag = false;
	scanf("%lld",&M);
	FOR(i,1,M)
		scanf("%lld",A+i);
	scanf("%lld",&N);
	FOR(i,1,N)
		scanf("%lld",B+i);
	FOR(i,1,M)
		FOR(j,1,N)
		{
			k = gcd(A[i],B[j]);
			res*=k;
			if(res >= MOD) flag = true;
			res%=MOD;
			A[i]/=k;
			B[j]/=k;
		}
	long long a = (int)log10(res) + 1;
	if(flag)
		FOR(i,1,9-a)
			printf("0");
	printf("%lld\n",res);
}
int main()
{
	solve();
	return 0;
}
