#include <iostream>
#include <algorithm>
#include <cstdio>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define f first
#define s second
#define MAXN 50000
using namespace std;
typedef pair < int , int > pii;
pii P[MAXN+5];
void solve()
{
	int N,bas,i,son;
	scanf("%d",&N);
	FOR(i,1,N)
		scanf("%d %d",&P[i].f,&P[i].s);
	sort(P+1,P+N+1);
	bas = P[1].f; son = P[1].s;
	FOR(i,2,N)
		if(P[i].f > son)
		{
			printf("%d %d\n",bas,son);
			bas = P[i].f; son = P[i].s;
		}
		else
			son = max( son , P[i].s );
	printf("%d %d\n",bas,son);
}
int main()
{
	solve();
	return 0;
}
