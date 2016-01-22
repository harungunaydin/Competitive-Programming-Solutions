#include <iostream>
#include <cstdio>
#define TFOR(i,a,b) for(i=a; i>=b; i--)
#define MAXN 100001
#define MOD 5000011
using namespace std;
int DP[MAXN];
int main()
{
	int K,N,i;
	scanf("%d %d",&N,&K);
	TFOR(i,N,1)
		DP[i] = ( (i + K + 1 > N) ? DP[i+1] + 1 : DP[i+1] + DP[i+K+1] + 1 ) % MOD;
	printf("%d\n" , DP[1] + 1);
	return 0;
}
