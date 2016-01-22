#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define MAXN 16
using namespace std;
int K,M,N;
int A[MAXN+5],used[MAXN+5],C[MAXN+5];
inline int gcd(int a,int b)
{
	return !b ? a : gcd(b,a%b);
}
void print()
{
	int i;
	FOR(i,1,N)
		printf("%d ",C[i]);
	exit(0);
}
inline void rec(int x)
{
	if(x == N + 1) { if(!(--M)) print(); return; }
	int i;
	FOR(i,1,N)
		if(!used[i])
		{
			if(gcd(A[i],C[x-1]) < K) continue;
			used[i] = true;
			C[x] = A[i];
			rec(x+1);
			used[i] = false;
		}
}
void solve()
{
	int i;
	scanf("%d %d %d",&N,&M,&K);
	FOR(i,1,N)
		scanf("%d",A+i);
	sort(A+1,A+N+1);
	if(M <= 50000000) rec(1);
	printf("-1\n");
}
int main()
{
	solve();
	return 0;
}
