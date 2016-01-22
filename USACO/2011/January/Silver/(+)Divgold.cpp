#include <iostream>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define TFOR(i,a,b) for(i=a; i>=b; i--)
using namespace std;
int A[1005],DP[100000005];
bool hash[10000005];
void solve()
{
	int N,i,j,k=1,s=0,top=0;
	scanf("%d",&N);
	FOR(i,1,N)
	{
		scanf("%d",&A[i]);
		top+=A[i];
	}
	DP[0]=1;
	FOR(i,1,N)
		for(j=top-A[i]; j>=0; j--)
			if(DP[j])
			{
				DP[j+A[i]]=(DP[j+A[i]]+DP[j])%1000000;
				hash[j+A[i]]=true;
			}
	TFOR(i,top/2,0)
		if(hash[i])
			break;
	printf("%d\n%d\n",abs( (top-i)-i) ,DP[i]);
}
int main()
{
	solve();
	return 0;
}
