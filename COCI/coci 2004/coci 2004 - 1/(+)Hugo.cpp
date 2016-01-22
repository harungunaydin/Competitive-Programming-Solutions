#include <iostream>
#define FOR(i,a,b) for(i=a; i<=b; i++)
using namespace std;
int maxi,N;
short DP[1005][100005];
bool A[1005][100005];
void solve()
{
	int i,j,s,x;
	bool *p;
	scanf("%d",&N);
	FOR(i,1,N)
	{
		scanf("%d",&s);
		p=*(A+i);
		FOR(j,1,s)
		{
			scanf("%d",&x);
			*(p+x)=1;
			if(x>maxi) maxi=x;
		}
	}
	for(i=maxi; i; i--)
		FOR(j,1,N)
			DP[j][i]=max(DP[j-1][i+1],max(DP[j][i+1],DP[j+1][i+1]))+A[j][i];
	printf("%d\n",DP[N/2+1][1]);
}
int main()
{
	solve();
	return 0;
}
