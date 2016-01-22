#include <iostream>
#include <cstdio>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define TFOR(i,a,b) for(i=a; i>=b; i--)
#define MAXN 
using namespace std;
int N;
int  A[MAXN+5][MAXN+5];
bool B[MAXN+5][MAXN+5];
void solve()
{
	int i,j,maxi,res(0);
	scanf("%d",&N);
	FOR(i,1,N)
		FOR(j,1,N)
			scanf("%d",A[i]+j);
	FOR(i,1,N)
	{
		maxi = 0;
		FOR(j,1,N)
			if(A[i][j] >= maxi)
			{
				maxi = A[i][j];
				B[i][j] = true;
			}
		maxi = 0;
		TFOR(j,N,1)
			if(A[i][j] >= maxi)
			{
				maxi = A[i][j];
				B[i][j] = true;
			}
	}
	FOR(j,1,N)
	{
		maxi = 0;
		FOR(i,1,N)
			if(A[i][j] >= maxi)
			{
				maxi = A[i][j];
				B[i][j] = true;
			}
		maxi = 0;
		TFOR(i,N,1)
			if(A[i][j] >= maxi)
			{
				maxi = A[i][j];
				B[i][j] = true;
			}
	}
	FOR(i,1,N)
		FOR(j,1,N)
			res+=(A[i][j] && B[i][j]);
	printf("%d\n",res);
}
int main()
{
	solve();
	return 0;
}
