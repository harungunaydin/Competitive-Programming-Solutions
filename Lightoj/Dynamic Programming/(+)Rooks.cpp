#include <cstdio>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define TFOR(i,a,b) for(i=a; i>=b; i--)
using namespace std;
int main()
{
	long long unsigned res;
	int K,N,T,i,j;
	scanf("%d",&T);
	FOR(i,1,T)
	{
		res = 1;
		scanf("%d %d",&N,&K);
		TFOR(j,N,N-K+1)
		{
			res *= j * j;
			res /= N - j + 1;
		}
		printf("Case %d: %lld\n", i , res);
	}
	return 0;
}
