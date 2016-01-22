#include <iostream>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define all(x) x.begin(),x.end()
#define MAXN 7
using namespace std;
int A[MAXN+5][MAXN+5];
void read()
{
	int i,j;
	FOR(i,1,2)
		FOR(j,1,3)
			scanf(" %c",A[i]+j+2);
	FOR(i,3,5)
		FOR(j,1,MAXN)
			scanf(" %c",A[i]+j);
	FOR(i,6,7)
		FOR(j,1,3)
			scanf(" %c",A[i]+j+2);
}
void solve()
{
	int i,j,res(0);
	FOR(i,1,MAXN)
		FOR(j,1,MAXN)
			if(A[i][j] == 'o')
			{
				res+=(A[i+1][j] == 'o' && A[i+2][j] == '.');
				res+=(A[i][j+1] == 'o' && A[i][j+2] == '.');
				res+=(A[i-1][j] == 'o' && A[i-2][j] == '.');
				res+=(A[i][j-1] == 'o' && A[i][j-2] == '.');
			}
	printf("%d\n",res);
}
int main()
{
	read();
	solve();
	return 0;
}
