#include <iostream>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define TFOR(i,a,b) for(i=a; i>=b; i--)
#define MAXN 1000
using namespace std;
string str[MAXN+5];
int M,N;
char A[MAXN+5][MAXN+5];
void solve()	
{
	int i,j,maxi(0);
	char c;
	scanf("%d %d",&M,&N);
	FOR(i,1,M)
		FOR(j,1,N)
			scanf(" %c",A[i]+j);
	FOR(j,1,N)
		TFOR(i,M,1)
			str[j]+=A[i][j];
	sort(str+1,str+N+1);
	FOR(i,1,N-1)
	{
		j = 0;
		while(str[i][j] == str[i+1][j] && j<M) j++;
		maxi = max(maxi,j);
	}
	printf("%d\n",M-maxi-1);
}
int main()
{
	solve();
	return 0;
}
