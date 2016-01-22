#include <iostream>
#include <cstdio>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define MAXN 10
using namespace std;
bool K[400];
void solve()
{
	int M,N,a,i,j,k;
	scanf("%d %d",&N,&M);
	FOR(i,1,N)
	{
		scanf("%d",&a);
		k = a;
		K[k]++;
		FOR2(j,360)
			K[k = (k+a)%360] = true;
	}
	FOR(j,1,M)
	{
		scanf("%d",&a);
		K[a] ? printf("YES\n") : printf("NO\n");
	}
}
int main()
{
	solve();
	return 0;
}
