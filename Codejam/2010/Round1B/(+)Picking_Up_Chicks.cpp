#include <iostream>
#include <cstdio>
#include <queue>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define TFOR(i,a,b) for(i=a; i>=b; i--)
#define MAXN 55
using namespace std;
typedef pair < int , int > pii;
priority_queue < int > pq;
int B,K,N,T;
int V[MAXN],X[MAXN];
void solve()
{
	int i,j,k(0),res(0),s(0),x;
	scanf("%d %d %d %d",&N,&K,&B,&T);
	FOR(i,1,N) scanf("%d",X+i);
	FOR(i,1,N) scanf("%d",V+i);

	TFOR(i,N,1)
	{
		if(B - X[i] > V[i] * T) s++;
		else
		{
			res += s;
			if(++k == K) break;
		}
	}
	if(k < K) printf("IMPOSSIBLE\n");
	else printf("%d\n" , res );
}
int main()
{
	freopen("inp","r",stdin);
	freopen("out","w",stdout);
	int T,i;
	scanf("%d",&T);
	FOR(i,1,T)
	{
		printf("Case #%d: ",i);
		solve();
	}
	return 0;
}
