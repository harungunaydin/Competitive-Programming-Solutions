#include <iostream>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define f first
#define s second
#define MAXN 100
using namespace std;
pair < int , pair < int , int > > P[MAXN+5];
int A[10005];
void solve()
{
	int N,i,j,res(0);
	scanf("%d",&N);
	FOR(i,1,N)	
		scanf("%d %d %d",&P[i].f,&P[i].s.f,&P[i].s.s);
	sort(P+1,P+N+1);
	FOR(i,1,N)
	{
		res+=P[i].f - A[P[i].s.f] + P[i].f - A[P[i].s.s-1];
		FOR(j,P[i].s.f,P[i].s.s-1)
			A[j] = P[i].f;
	}
	printf("%d\n",res);
}
int main()
{
	solve();
	return 0;
}
