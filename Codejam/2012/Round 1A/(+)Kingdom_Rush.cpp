#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define TFOR(i,a,b) for(i=a; i>=b; i--)
#define f first
#define s second
#define MAXN 1005
using namespace std;
typedef pair < int , int > pii;
inline bool cmp( const pii &a , const pii &b ) { return a.s > b.s; }
pii H[MAXN] , P[MAXN];
void solve()
{
	memset( H , 0 , sizeof H );
	int N,i,res(0),s(0);
	scanf("%d",&N);
	FOR(i,1,N)
		scanf("%d %d",&P[i].f,&P[i].s);

	sort(P+1,P+N+1,cmp);

	while(1)
	{
		FOR(i,1,N)
			if(!H[i].s && s >= P[i].s)
			{
				s += (H[i].f) ? 1 : 2;
				H[i].s = true;
				res++;
				i = 0;
			}

		FOR(i,1,N)
			if(!H[i].f && !H[i].s && s >= P[i].f)
			{
				s++;
				H[i].f = true;
				res++;
				break;
			}

		if(i == N + 1) break;

	}
	FOR(i,1,N)
		if(!H[i].s)
		{
			printf("Too Bad\n");
			return;
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
