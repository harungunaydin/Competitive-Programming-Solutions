#include <iostream>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
using namespace std;
int A[100];
void solve()
{
	int N,i,s(0);
	scanf("%d",&N);
	while(N)
	{
		A[s++] = N%10;
		N/=10;
	}
	reverse(A,A+s);
	int k = next_permutation(A,A+s);
	if(!k) printf("0");
	else
		FOR2(i,s)
			printf("%d",A[i]);
}
int main()
{
	solve();
	return 0;
}
