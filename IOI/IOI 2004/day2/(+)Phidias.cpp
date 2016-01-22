#include <iostream>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n)  FOR(i,0,n-1)
#define f first
#define s second
#define MAXN 600
using namespace std;
typedef pair <int,int> pii;
int M,N,K;
pii A[MAXN];
int DP[MAXN+5][MAXN+5];
int solve(int x,int y)
{		
	if(DP[x][y]) return DP[x][y];
	int i,Max=0;
	FOR(i,1,K)
	{
		if(x < A[i].f) break;
		if(y>=A[i].s)
		{
			Max = max(Max,solve(A[i].f,y-A[i].s) + solve(x-A[i].f,y) + A[i].f*A[i].s);
			Max = max(Max,solve(x-A[i].f,A[i].s) + solve(x,y-A[i].s) + A[i].f*A[i].s);
		}
	}
	return DP[x][y] = Max;
}
void read()
{
	int i;
	scanf("%d %d %d",&N,&M,&K);
	FOR(i,1,K)
		scanf("%d %d",&A[i].s,&A[i].f);
	sort(A+1,A+K+1);
}
int main()
{
	read();
	printf("%d\n",M*N - solve(M,N));
	return 0;
}
