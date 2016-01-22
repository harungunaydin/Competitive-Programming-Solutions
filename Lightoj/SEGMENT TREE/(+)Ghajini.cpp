#include <iostream>
#include <cstdio>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define f first
#define s second
#define MAX(a,b) ( (a) > (b) ? (a) : (b) )
#define MIN(a,b) ( (a) < (b) ? (a) : (b) )
#define OO 1000000000
#define MAXN 100005
using namespace std;
typedef pair < int , int > pii;
pii ST[3*MAXN];
int A[MAXN];
inline pii init(int pos,int s,int e)
{
	if(s == e) return ST[pos] = make_pair(A[s],A[s]);
	register int m = ( s + e ) / 2;
	register pii p1 = init(pos*2,s,m);
	register pii p2 = init(pos*2+1,m+1,e);
	return ST[pos] = make_pair( MIN(p1.f,p2.f) , MAX(p1.s,p2.s)  );
}
inline pii find(int pos,int s,int e,int a,int b)
{
	if(a > e || b < s) return make_pair(OO,0);
	if(a <= s && e <= b) return ST[pos];
	register int m = ( s + e ) / 2;
	register pii p1 = find(pos*2,s,m,a,b);
	register pii p2 = find(pos*2+1,m+1,e,a,b);
	return make_pair( MIN(p1.f,p2.f) , MAX(p1.s,p2.s) );
}
void solve()
{
	register pii t;
	register int D,N,i,res(0);
	scanf("%d %d",&N,&D);
	FOR(i,1,N) scanf("%d",A+i);
	init(1,1,N);
	FOR(i,1,N-D+1)
	{
		t = find(1,1,N,i,i+D-1);
		res = MAX( res , t.s - t.f );
	}
	printf("%d\n" , res );
}
int main()
{
	register int T,i;
	scanf("%d",&T);
	FOR(i,1,T)
	{
		printf("Case %d: ",i);
		solve();
	}
	return 0;
}
