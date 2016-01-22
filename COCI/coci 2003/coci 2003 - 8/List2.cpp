#include <iostream>
#define FOR(i,a,b) for(i=a; i<=b; i++)
using namespace std;
int N;
int A[1000005],B[1000005];
int bul(int x)
{
	int i,s=0;
	FOR(i,x,N)
		if(!A[i])
			return i;
	x--;
	FOR(i,1,x)
		if(!A[i])
			return i;
	return 0;
}
void solve()
{
	int a,i,k,x;
	scanf("%d",&N);
	FOR(i,1,N-1)
	{
		scanf("%d",&x);
		B[i]=x;
		A[x]++;
	}
	FOR(i,1,N-1)
	{
		k=B[i];
		a=bul(k);
		A[a]--;
		A[k]--;
		printf("%d %d\n",k,a);
	}
}
int main()
{
	solve();
	return 0;
}
