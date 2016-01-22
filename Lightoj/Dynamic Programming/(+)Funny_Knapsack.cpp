#include <algorithm>
#include <cstdio>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define MAXN 35
using namespace std;
int K;
int N,a,b,c,d;
int A[MAXN] , B[MAXN];
long long C[(1<<15)+1] , D[(1<<15)+1];
void rec1(int x,long long s)
{
	if(x == a + 1) { C[++c] = s; return; }
	rec1(x+1,s);
	if(s + A[x] <= K)
		rec1(x+1,s+A[x]);
}
void rec2(int x,long long s)
{
	if(x == b + 1) { D[++d] = s; return; }
	rec2(x+1,s);
	if(s + B[x] <= K)
		rec2(x+1,s + B[x]);
}
void solve()
{
	c = d = 0;
	int res(0);
	int i;
	scanf("%d %d",&N,&K);
	a = N / 2;
	FOR(i,1,a) scanf("%d",A+i);
	b = N - N/2;
	FOR(i,1,b) scanf("%d",B+i);
	
	rec1(1,0);

	rec2(1,0);

	sort(D+1,D+d+1);

	FOR(i,1,c)
		res += upper_bound(D+1,D+d+1,K-C[i]) - D - 1;

	printf("%d\n" , res );
}
int main()
{
	int T,i;
	scanf("%d",&T);
	FOR(i,1,T)
	{
		printf("Case %d: ",i);
		solve();
	}
	return 0;
}
