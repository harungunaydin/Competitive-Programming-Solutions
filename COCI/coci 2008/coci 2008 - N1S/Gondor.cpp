#include <iostream>
#include <cmath>
#include <queue>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define f first
#define s second
#define Distance(a,b) ( sqrt ( ((b.f) - (a.f)) * ((b.f) - (a.f)) + ((b.s) - (a.s)) * ((b.s) - (a.s)) ) )
#define EKLE(x,s) pq.push(make_pair(-(s),x))
#define BAK(x,s)  { x = pq.top().s; s = - pq.top().f; pq.pop(); }
#define MAXN 100
using namespace std;
typedef pair < int , int > pii;
priority_queue < pair < double , int > > pq;
pii P[MAXN+5];
double RES[MAXN+5];
int N;
int A[MAXN+5][MAXN+5];
bool burned[MAXN+5];
void solve()
{
	int i,j,k(0),x;
	double s;
	scanf("%d",&N);
	FOR(i,1,N)
	{
		scanf("%d %d %d",&P[i].f,&P[i].s,A[i]);
		FOR(j,1,N-1)
			scanf("%d",A[i]+j);
	}
	EKLE(1,0);
	while(!pq.empty())
	{
		BAK(x,s);
		if(!burned[x])
		{
			RES[x] = s;
			if(++k == N) break;
			burned[x] = true;
		}
		FOR(i,1,N)
			if(!burned[A[x][i]] && A[x][0])
			{
				A[x][0]--;
				EKLE(A[x][i],s + Distance(P[x],P[A[x][i]]));
			}
	}
	FOR(i,1,N)
		if(abs(RES[i]) < 0.0000001)
			RES[i] = +0;
	FOR(i,1,N)
		printf("%.6lf\n",RES[i]);
}
int main()
{
	solve();
	return 0;
}
