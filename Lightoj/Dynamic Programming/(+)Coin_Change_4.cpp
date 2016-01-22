#include <algorithm>
#include <cstdio>
#include <iostream>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define MAXN 10
using namespace std;
int K,N,a,b,c,d;
int A[MAXN] , B[MAXN] , C[19684] , D[19684];
void rec1(int x,int s)
{
	if(s > K) return;
	if(x == a + 1) { C[++c] = K - s; return; }
	rec1(x+1,s);
	rec1(x+1,s + A[x]);
	rec1(x+1,s + 2 * A[x] );
}
void rec2(int x,int s)
{
	if(s > K) return;
	if(x == b + 1) { D[++d] = s; return; }
	rec2(x+1,s);
	rec2(x+1,s + B[x]);
	rec2(x+1,s + 2 * B[x] );
}
void solve()
{
	c = d = 0;
	int i,t;
	scanf("%d %d",&N,&K);

	a = N / 2;
	
	FOR(i,1,a) scanf("%d",A+i);

	b = N - N / 2;

	FOR(i,1,b) scanf("%d",B+i);

	rec1(1,0);
	rec2(1,0);
	
	sort(D+1,D+d+1);

	FOR(i,1,c)
		if(  * lower_bound(D+1,D+d+1 , C[i])  == C[i] )
		{
			printf("Yes\n");
			return;
		}
	printf("No\n");
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
