#include <iostream>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define hesapla(x,y) (DP[y]-DP[x-1])
using namespace std;
int N,S;
int A[100005],DP[100005];
void solve()
{
	int a,b,i,j,k;
	scanf("%d %d",&N,&S);
	FOR(i,1,N) scanf("%d",&A[i]);
	FOR(i,1,N) DP[i]=A[i]+DP[i-1];
	FOR(i,1,N)
	{
		k=(N-i+1)/2;
		while(k)
		{
			if(hesapla(i,i+k-1)<=S && hesapla(i+k,i+2*k-1)<=S) break;
			k--;
		}
		printf("%d\n",k*2);
	}
}
int main()
{
	solve();
	return 0;
}
