#include <cstdio>
#include <iostream>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define TFOR(i,a,b) for(i=a; i>=b; i--)
#define MIN(a,b) ( (a) < (b) ? (a) : (b) )
#define x first
#define y second
#define MAXN 20005
#define MAXK 2005
using namespace std;
typedef pair < int , int > pii;
inline int Abs( int a ) { return a > 0 ? a : -a; }
inline int Min( int a , int b ) { return a < b ? a : b; }
pii P[MAXN];
int X[2][MAXK] , Y[2][MAXK];
long long A[25000*25000];
void solve()
{
	int N,i,j,k,cur(0),pre(1);
	scanf("%d",&N);
	FOR(i,0,2000) X[cur][i] = Y[cur][i] = Abs(1000 - i);

	P[0] = make_pair(1000,1000);

	FOR(i,1,N)
	{
		pre = !pre;
		cur = !cur;
		scanf("%d %d",&P[i].x,&P[i].y);
		P[i].x += 1000;
		P[i].y += 1000;

		FOR(j,0,2000)
				X[cur][j] = Min( X[pre][j] + Abs(P[i].x - P[i-1].x) , Y[pre][ P[i].x ] + Abs(P[i-1].y - j) );
		FOR(j,0,2000)
				Y[cur][j] = Min( Y[pre][j] + Abs(P[i].y - P[i-1].y) , X[pre][ P[i].y ] + Abs(P[i-1].x - j) );
	}

	int res(1000000000);

	FOR(i,0,2000)
		res = MIN( res , X[cur][i] );

	FOR(i,0,2000)
		res = MIN( res , Y[cur][i] );

	printf("%d\n" , res );


}
int main()
{
	solve();
	return 0;
}
