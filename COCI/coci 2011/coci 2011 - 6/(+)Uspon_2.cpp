#include <iostream>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define MAXN 1000
using namespace std;
int A[MAXN+5];
void solve()
{
	int N,i,k,res(0);
	scanf("%d",&N);
	FOR(i,1,N)
		scanf("%d",A+i);
	FOR(i,1,N)
	{
		k = i;
		while(A[i] < A[i+1] && i<N) i++;
		res = max(res,A[i]-A[k]);
	}
	printf("%d\n",res);
}
int main()
{
	solve();
	return 0;
}
