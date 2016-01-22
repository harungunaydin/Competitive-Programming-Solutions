#include <iostream>
#define FOR(i,a,b) for(i=a; i<=b; i++)
using namespace std;
int A[100005];
void solve()
{
	int N,i,s=0;
	scanf("%d",&N);
	FOR(i,1,N)
		scanf("%d",&A[i]);
	for(i=N; i; i--)
		if(A[i-1]>=A[i])
		{
			s+=A[i-1]-A[i]+1;
			A[i-1]=A[i]-1;
		}
	printf("%d\n",s);
}
int main()
{
	solve();
	return 0;
}
