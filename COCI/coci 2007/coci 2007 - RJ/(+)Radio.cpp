#include <iostream>
#include <cmath>
#include <cstdio>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define MAXN 5
using namespace std;
int C[MAXN+5];
void solve()
{
	int A,B,N,i,res;
	scanf("%d %d",&A,&B);
	scanf("%d",&N);
	res = abs( A - B );
	FOR(i,1,N)
		scanf("%d",C+i);
	FOR(i,1,N)
		res = min( res , (int) abs( B - C[i] ) + 1);
	printf("%d\n",res);
}
int main()
{
	solve();
	return 0;
}
