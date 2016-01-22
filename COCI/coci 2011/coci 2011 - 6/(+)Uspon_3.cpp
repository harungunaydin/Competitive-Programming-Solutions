#include <iostream>
#define FOR(i,a,b) for(i=a; i<=b; i++)
using namespace std;
int A[1005];
void solve()
{
	int N,i,maxi=0,s=1;
	scanf("%d",&N);
	FOR(i,1,N)
		scanf("%d",&A[i]);
	FOR(i,1,N)
	{
		if(A[i+1]>A[i])
			s++;
		else
		{
			maxi=max(maxi,A[i]-A[i-s+1]);
			s=1;
		}
	}
	printf("%d\n",maxi);
}
int main()
{
	solve();
	return 0;
}
