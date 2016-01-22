#include <iostream>
#include <algorithm>
#include <cstdio>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define all(x) x.begin(),x.end()
#define MAXN 100000
using namespace std;
int N;
int A[MAXN+5];
bool H[10005];
void solve()
{
	int i,res(0);
	scanf("%d",&N);
	FOR(i,1,N) scanf("%d",A+i);
	sort(A+1,A+N+1);
	FOR(i,1,N/2)
		res += A[i] + A[N-i+1] + A[N-i+1] - A[i];
	res+=(N&1) * A[N/2+1];
	printf("%d\n",res);
}
int main()
{
	solve();
	return 0;
}
