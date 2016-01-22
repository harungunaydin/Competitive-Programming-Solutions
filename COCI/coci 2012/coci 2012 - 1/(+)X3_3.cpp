#include <iostream>
#define FOR(i,a,b) for(i=a; i<=b; i++)
using namespace std;
int A[1000005];
void solve()
{
	long long  a,N,i,j,maske=1;
	long long s=0;
	scanf("%lld",&N);
	FOR(i,1,N)
		scanf("%lld",&A[i]);
	FOR(i,1,20)
	{
		a=0;
		FOR(j,1,N)
			if(A[j]&maske)
				a++;
		s+=a*abs(N-a)*maske;
		maske <<=1;
	}
	printf("%lld\n",s);
}
int main()
{
	solve();
	return 0;
}
