#include <iostream>
#include <cstdio>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define MAX(a,b) ( (a) > (b) ? (a) : (b) )
#define f first
#define s second
#define MAXN 30005
using namespace std;
typedef pair < short , short > pii;
pii sta[MAXN];
void solve()
{
	register short N,a,bas(0),f;
	register int i,res(0);
	register short A[MAXN];
	scanf("%hd",&N);
	FOR(i,1,N) scanf("%hd",A+i);
	A[++N] = -1;
	FOR(i,1,N)
	{
		a = A[i];
		f = i;
		while(bas && a < sta[bas].s)
		{
			f = sta[bas].f;
			res = MAX( res , (i - sta[bas].f) * sta[bas].s);
			bas--;
		}
		sta[++bas] = make_pair(f,a);
	}
	printf("%d\n", res );
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
