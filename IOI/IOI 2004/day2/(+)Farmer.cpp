#include <iostream>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define TFOR(i,a,b) for(i=a; i>=b; i--)
#define MAXN 2000
using namespace std;
int A[MAXN+5],B[MAXN+5];
bool DP[500000];
int solve()
{
	int K,M,Q,a,i,j,res,sum=0;
	scanf("%d %d %d",&Q,&M,&K);
	DP[0] = true;
	FOR(i,1,M)
	{
		scanf("%d",A+i);
		sum+=A[i];
	}
	FOR(i,1,K)
		scanf("%d",B+i);
	FOR(i,1,M)
		TFOR(j,sum,A[i])
			if(DP[j-A[i]])
				DP[j] = true;
	if(DP[Q]) return Q;
	if(sum > Q) return Q-1;
	res = sum;
	sort(B+1,B+K+1,greater <int>());
	FOR(i,1,K)
		if((res+=B[i]) >= Q)
			return Q-i;
}
int main()
{
	printf("%d\n",solve());
	return 0;
}
