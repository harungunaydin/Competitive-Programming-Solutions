#include <iostream>
#include <cstdio>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define f first
#define s second
#define MAXN 1005
using namespace std;
typedef pair < int , int > pii;
pii A[MAXN];
void solve()
{
	int N,i,j,res(0);
	scanf("%d",&N);
	FOR(i,1,N)
		scanf("%d %d",&A[i].f,&A[i].s);

	FOR(i,1,N)
		FOR(j,i+1,N)
		{
			if(A[i].f < A[j].f && A[i].s > A[j].s) res++;
			else if(A[i].f > A[j].f && A[i].s < A[j].s) res++;
		}
	printf("%d\n" , res );
}
int main()
{
	int T,i;
	scanf("%d",&T);
	FOR(i,1,T)
	{
		printf("Case #%d: ",i);
		solve();
	}
	return 0;
}
