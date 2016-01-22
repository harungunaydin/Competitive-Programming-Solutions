#include <iostream>
#define FOR(i,a,b) for(i=a; i<=b; i++)
using namespace std;
int A[300005];
void solve()
{
	int N,i,k,maxi,s=0;
	scanf("%d",&N);
	FOR(i,1,N)
	{
		scanf("%d",&A[i]);
		if(A[i]==N) k=i;
	}
	maxi=N;
	for(i=k; i; i--)
		if(A[i]==maxi && ++s)
			maxi--;
	printf("%d\n",N-s);
}
int main()
{
	solve();
	return 0;
}
