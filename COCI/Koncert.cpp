#include <iostream>
#include <cstdio>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define MAXN 100000
using namespace std;
int M,M2,N,N2;
int A[MAXN+5],B[MAXN+5];
void solve()
{
	int a,i,k(1);
	scanf("%d %d",&N,&N2);
	FOR(i,1,N2)
	{
		scanf("%d",&a);
		A[a] = true;
	}
	scanf("%d %d",&M,&M2);
	FOR(i,1,M2)
		scanf("%d",B+i);
	FOR(i,1,M2)
	{
		if(k == N) break;
		while(A[k]) k++;
		if(k == N + 1) break;
		A[k] = true;
		printf("GIVE GIRL %d GUY %d\n",B[i],k);
	}
	FOR(i,1,N)
		printf("ENTER GUY %d\n",i);
}
int main()
{
	solve();
	return 0;
}
