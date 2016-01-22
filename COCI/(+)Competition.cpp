#include <iostream>
#include <cstdio>
#include <queue>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define EKLE(x,tur,s) pq.push(make_pair( -(s), make_pair(x,tur)))
#define BAK(x,tur,s) { x = pq.top().second.first; tur = pq.top().second.second; s = - pq.top().first; pq.pop(); }
#define f first
#define s second
#define MAXN 10000
using namespace std;
typedef pair < int , int > pii;
priority_queue < pair < int , pii > > pq;
pii P[MAXN+5];
int A[MAXN+5];
void solve()
{
	int M,N,hiz,i,k,pre(-1),res(0),s,tur,x;
	scanf("%d %d",&N,&M);
	FOR(i,1,N)
		scanf("%d %d",&P[i].f,&P[i].s);
	FOR(i,1,N)
		EKLE(i,0,0);
	while(!pq.empty())
	{
		BAK(x,tur,s);
		k = (s && pre == s) ? k + 1 : 0;
		res = max( res , k );
		pre = s;
		if(tur == M) continue;
		hiz = (!(tur%P[x].s)) ? P[x].f : P[x].f + tur%P[x].s;
		EKLE(x,tur+1,s+hiz);
	}
	printf("%d\n",res + 1);
}
int main()
{
	solve();
	return 0;
}
