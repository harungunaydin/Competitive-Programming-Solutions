#include <iostream>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define all(x) x.begin(),x.end()
#define MAXN 6
using namespace std;
int A[MAXN+5] = {0,1,1,2,2,2,8};
void solve()
{
	int a,i;
	FOR(i,1,MAXN)
	{
		scanf("%d",&a);
		printf("%d",A[i]-a);
		if(i < MAXN) printf(" ");
	}
	printf("\n");
}
int main()
{
	solve();
	return 0;
}
