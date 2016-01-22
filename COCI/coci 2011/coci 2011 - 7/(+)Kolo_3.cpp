#include <iostream>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define TFOR(i,a,b) for(i=a; i>=b; i--)
using namespace std;
int K,N;
char A[105];
int hash[200];
void solve()
{
	int i,k=0,x;
	char c;
	scanf("%d %d",&N,&K);
	FOR(i,1,K)
	{
		scanf("%d %c",&x,&c);
		k = (k+x) % N;
		if(hash[c] && hash[c] != k) { printf("!"); return; }
		hash[c] = k;
		if(A[k] && A[k]!=c) { printf("!"); return; }
		if(!A[k]) A[k] = c;
	}
	for(i=k; i>=0; i--)
		(A[i])? printf("%c",A[i]) : printf("?");
	for(i=N-1; i>k; i--)
		(A[i])? printf("%c",A[i]) : printf("?");
}
int main()
{
	solve();
	printf("\n");
	return 0;
}
