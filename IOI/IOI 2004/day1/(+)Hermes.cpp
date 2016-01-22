#include <iostream>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define f first
#define s second
#define MAXN 20000
#define MAXL 1000
#define ABS(a) (a>0 ? (a) : -(a))
#define MIN(a,b) (a < b ? a : b)
#define INF 2000000000
using namespace std;
typedef pair <int,int> pii;
pii A[MAXN+5];
int N,d;
pii DP[2][2005];
void read()
{
	int a,b,i;
	scanf("%d",&N);
	FOR(i,1,N)
	{
		scanf("%d %d",&A[i].f,&A[i].s);
		A[i].f+=MAXL; A[i].s+=MAXL;
	}
}
void solve()
{
	int M,i,j,k=0,res=INF;
	M = MAXL*2;
	A[0].f = A[0].s = MAXL;
	FOR(i,0,M) DP[0][i].f = DP[0][i].s = abs(i-MAXL);
	FOR(i,1,N)
	{
		k = !k;
		FOR(j,0,M)
		{
			DP[k][j].f = MIN(DP[!k][j].f+ABS(A[i].f-A[i-1].f),DP[!k][A[i].f].s+ABS(j-A[i-1].s));
			DP[k][j].s = MIN(DP[!k][j].s+ABS(A[i].s-A[i-1].s),DP[!k][A[i].s].f+ABS(j-A[i-1].f));
		}
	}
	FOR(i,0,M)
		res = MIN(res,MIN(DP[k][i].f,DP[k][i].s));
	printf("%d\n",res);
}
int main()
{
	read();
	solve();
	return 0;
}
