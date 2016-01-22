#include <iostream>
#include <cstdio>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define TFOR(i,a,b) for(i=a; i>=b; i--)
#define FOR2(i,n) FOR(i,0,n-1)
#define MAXN 
using namespace std;
void solve()
{
	int M,N,K,i,res=0;
	scanf("%d %d %d",&M,&N,&K);
	FOR2(i,K+1)
		res = max(res,min((M-i)/2,N-K+i));
	printf("%d\n",res);
}
int main()
{
	solve();
	return 0;
}
