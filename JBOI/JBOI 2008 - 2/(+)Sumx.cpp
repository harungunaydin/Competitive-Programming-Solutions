#include <iostream>
#include <cstdio>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define MAXN 1000000
using namespace std;
int A[MAXN+5];
bool B[MAXN+5];
void solve()
{
	int N,X,a,i,res(0);
	scanf("%d",&N);
	FOR(i,1,N)
	{
		scanf("%d",A+i);
		B[A[i]] = true;
	}
	scanf("%d",&X);
	FOR(i,1,N)
		if(A[i] < X)
			res+=B[X-A[i]];
	printf("%d\n",res/2);
}
int main()
{
	solve();
	return 0;
}
