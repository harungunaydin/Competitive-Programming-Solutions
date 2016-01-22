#include <iostream>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define INF 100000000
#define MAXN 1000
using namespace std;
int N;
int A[MAXN+5];
int DP[MAXN+5][MAXN+5];
int jump(int x,int s)
{
	if(x < 1 || x > N) return INF;
	if(DP[x][s]) return DP[x][s];
	if(x == N) return A[N];
	return DP[x][s] = min( jump(x+s+1,s+1) , jump(x-s,s) ) + A[x];
}
int main()
{
	int i;
	scanf("%d",&N);
	FOR(i,1,N) scanf("%d",A+i);
	printf("%d\n",jump(2,1));
	return 0;
}
