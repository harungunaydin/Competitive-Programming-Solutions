#include <iostream>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define MAXN 1000000
using namespace std;
int A[MAXN+5];
int solve()
{
	int K,N,i,k;
	scanf("%d %d",&N,&K);
	FOR(i,1,N)
		scanf("%d",A+i);
	sort(A+1,A+N+1);
	FOR(i,1,N)
	{
		k = i++;
		while(A[i] == A[k] && i <= N) i++;
		if((i-k)%K) return A[k];
		i--;
	}
}
int main()
{
	printf("%d\n",solve());
	return 0;
}
