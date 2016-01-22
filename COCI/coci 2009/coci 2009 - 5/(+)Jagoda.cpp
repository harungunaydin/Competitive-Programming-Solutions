#include <iostream>
#include <cmath>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define MAXN 100000
using namespace std;
long long K,M,N;
long long KASE[MAXN+5],KUTU[MAXN+5];
void solve()
{
	long long a,b,i,j,s;
	scanf("%lld %lld",&N,&M);
	K = (int) sqrt(N);
	FOR(i,1,M)
	{
		scanf("%lld %lld",&b,&a);
		b+=a-1;
		a--; b--;
		s = 0;
		for(j=a; j<=b; j++)
			if(!(j%K) && ((j+K-1)<=b || b == N-1))
			{
				s+=(++KASE[j/K]);
				j+=K-1;
			}
			else
				s+=(++KUTU[j]);
		printf("%lld\n",s);
	}
}
int main()
{
	solve();
	return 0;
}
