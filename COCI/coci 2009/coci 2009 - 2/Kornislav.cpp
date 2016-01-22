#include <iostream>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define all(x) x.begin(),x.end()
#define MAXN 4
using namespace std;
int A[MAXN+5];
void solve()
{
	int i,res(0);
	FOR2(i,MAXN)
		scanf("%d",A+i);
	sort(A,A+MAXN);
	do
	{
		res = max(res,min(A[0],A[2])*min(A[1],A[3]));
	}while(next_permutation(A,A+MAXN));
	printf("%d\n",res);
}
int main()
{
	solve();
	return 0;
}
