#include <iostream>
#include <algorithm>
#include <cstdio>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define all(x) x.begin(),x.end()
#define MAXN 300000
using namespace std;
int A[MAXN+5];
void solve()
{
	int N,i,maxi(0);
	scanf("%d",&N);
	FOR(i,1,N) scanf("%d",A+i);
	sort(A+1,A+N+1,greater <int> () );
	FOR(i,1,N)
	{
		if(A[i] + N < maxi) break;
		maxi = max( maxi , A[i] + i );
	}
	printf("%d\n",i-1);
}
int main()
{
	solve();
	return 0;
}
