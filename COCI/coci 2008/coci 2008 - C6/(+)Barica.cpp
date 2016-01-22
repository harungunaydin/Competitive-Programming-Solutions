#include <iostream>
#include <cstdio>
#include <algorithm>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define f first
#define s second
#define MAXN 300000
#define MAXL 100000
using namespace std;
typedef pair < int , int > pii;
pair < pii , int > P[MAXN+5];
int DP[MAXN+5],DPX[MAXL+5],DPY[MAXL+5];
void solve()
{
	int K,N,a,b,i,x,x2,y,y2;
	scanf("%d %d",&N,&K);
	FOR(i,1,N)
		scanf("%d %d %d",&P[i].f.f,&P[i].f.s,&P[i].s);
	x = P[1].f.f; y = P[1].f.s;
	x2 = P[N].f.f; y2 = P[N].f.s;
	sort(P+1,P+N+1);
	FOR(i,1,N)
		if(P[i].f.f == x && P[i].f.s == y)
			a = i;
		else if(P[i].f.f == x2 && P[i].f.s == y2)
			b = i;
	DP[a]=P[a].s;
	DPX[P[a].f.f]=P[a].s;
	DPY[P[a].f.s]=P[a].s;
	FOR(i,a+1,b)
	{
		x = P[i].f.f; y = P[i].f.s;
		if(max ( DPX[x] , DPY[y] ) - K < 0)	continue;
		DP[i]  = max ( DPX[x] , DPY[y] ) + P[i].s - K;
		DPX[x] = max ( DPX[x] , DP[i] );
		DPY[y] = max ( DPY[y] , DP[i] );
	}
	printf("%d\n",DP[b]);
}
int main()
{
	solve();
	return 0;
}
