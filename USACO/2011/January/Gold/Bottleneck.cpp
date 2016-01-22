#include <iostream>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define TFOR(i,a,b) for(i=a; i>=b; i--)
using namespace std;
int K,N;
int A[100005],B[100005],C[100005];
int A2[100005],B2[100005],C[100005];
void hallet()
{
	int i;
	TFOR(i,N,2)
	{
		if(B2[i] > C2[i])
		{
			B2[A2[i]]+=C2[i];
			B2[i]-=C2[i];
		}
		else
		{
			B2[A[i]]+=B2[i];
			B2[i]=0;
		}
	}
}
void solve()
{
	int i,j,x;
	scanf("%d %d",&N,&K);
	FOR(i,2,N)
		scanf("%d %d %d",&A[i],&B[i],&C[i]);
	FOR(i,1,K)
	{
		scanf("%d",&x);
		FOR(i,1,N)
		FOR(j,1,x) hallet();
		printf("%d\n",B[1]);
	}
}
int main()
{
	solve();
	return 0;
}
