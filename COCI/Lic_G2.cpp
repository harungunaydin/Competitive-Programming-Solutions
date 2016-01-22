#include <iostream>
#include <cstdio>
#include <map>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define all(x) x.begin(),x.end()
#define MAXN 15000000
using namespace std;
short A[MAXN+5];
void solve()
{
	int N,i,j,maxi(0),res;
	scanf("%d",&N);
	FOR(i,1,N)
		for(j = i; j<=N; j+=i)
			A[j]++;
	FOR(i,1,N)
		if(A[i] > maxi) { maxi = A[i]; res = i; }
	printf("%d\n",res);
}
int main()
{
	solve();
	return 0;
}
