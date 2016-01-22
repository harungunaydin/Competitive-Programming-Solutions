#include <iostream>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define all(x) x.begin(),x.end()
#define MAXN 25
using namespace std;
int hash[MAXN+5];
char A[MAXN+5];
void solve()
{
	int M,N,a,i,j,k(0);
	char c;
	scanf("%d %d",&N,&M);
	FOR(i,1,M)
	{
		scanf("%d %c",&a,&c);
		k = (k+a)%N;
		if((A[k] && A[k] != c) || (hash[c] && hash[c] != k)) { printf("!\n"); return; }
		hash[c] = k;
		A[k] = c;
	}
	for(i=k; i>=0; i--)
		printf("%c",(A[i] ? A[i] : '?'));
	for(i=N-1; i>k; i--)
		printf("%c",(A[i] ? A[i] : '?'));
	printf("\n");
}
int main()
{
	solve();
	return 0;
}
