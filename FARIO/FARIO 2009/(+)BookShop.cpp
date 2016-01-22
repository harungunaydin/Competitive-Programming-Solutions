#include <iostream>
#include <cstdio>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define MAXN 100005
using namespace std;
void solve()
{
	register int M,N,a,i,k(0);
	register int A[MAXN];
	scanf("%d",&N);
	FOR(i,1,N) scanf("%d",A+i);
	scanf("%d",&M);
	FOR(i,1,M)
	{
		scanf("%d",&a);
		while(1)
			if(A[++k] == a)
				break;
		printf("%d\n" , k );
	}
}
int main()
{
	solve();
	return 0;
}
