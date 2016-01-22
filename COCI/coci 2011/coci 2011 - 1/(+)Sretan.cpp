#include <algorithm>
#include <cstdio>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define TFOR(i,a,b) for(i=a; i>=b; i--)
#define all(x) x.begin(),x.end()
using namespace std;
long long K;
long long us[50];
void solve()
{
	long long i;
	scanf("%lld",&K);
	us[0] = 1;
	FOR(i,1,35)
		us[i] = us[i-1] * 2ll;

	i = 1;
	while(1)
	{
		if(K <= us[i]) break;
		K -= us[i++];
	}
	long long N = i;

	FOR(i,1,N)
	{
		if(K > us[N-i])
		{
			K -= us[N-i];
			printf("7");
		}
		else printf("4");
	}
	printf("\n");

}
int main()
{
	solve();
	return 0;
}
