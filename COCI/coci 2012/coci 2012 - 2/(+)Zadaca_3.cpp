#include <iostream>
#include <cmath>
#define FOR(i,a,b) for(i=a; i<=b; i++)
using namespace std;
int M,N;
int A[1005],B[1005];
int gcd(int a,int b)
{
	return (!b)? a : gcd(b,a%b);
}
void solve()
{
	int i,j;
	long long unsigned result=1,t;
	bool flag=false;
	scanf("%d",&N);
	FOR(i,1,N)
		scanf("%d",&A[i]);
	scanf("%d",&M);
	FOR(i,1,M)
		scanf("%d",&B[i]);
	FOR(i,1,N)
		FOR(j,1,M)
		{
			t=gcd(A[i],B[j]);
			result*=t;
			if(result > 1000000000) flag=true;
			result%=1000000000;
			A[i]/=t;
			B[j]/=t;
		}
	if(flag && result < 1000000000)
		for(i=1; i<=8-(int)log10(result); i++)
			printf("0");
	printf("%lld\n",result);
}
int main()
{
	solve();
	return 0;
}
