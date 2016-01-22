#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define f first
#define s second
#define MAXN 200001
using namespace std;
typedef pair < int , int > pii;
pii P[MAXN];
void solve()
{
	long long res(0);
	int M,N,i,j;
	scanf("%d %d",&M,&N);
	N += M;
	FOR(i,1,N)
		scanf("%d %d",&P[i].f,&P[i].s);
	sort(P+1,P+N+1);
	FOR(i,0,N) P[i].f = 0;
	FOR(i,1,N)
	{
		for(j = P[i].s; j <= N; j += j&-j ) res += P[j].f;
		for(j = P[i].s; j ; j -= j&-j) P[j].f++;
	}
	printf("%lld\n" , res );
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
