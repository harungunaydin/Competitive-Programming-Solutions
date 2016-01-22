#include <iostream>
#include <cstdio>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define TFOR(i,a,b) for(i=a; i>=b; i--)
#define INF 2000000000
#define f first
#define s second
#define MAXN 100001
using namespace std;
typedef pair < int , int > pii;
inline int Min( int a , int b ) { return a < b ? a : b; }
pii ST[(1 << 18) + 5];
int N;
int A[MAXN];
int init(int pos,int s,int e)
{
	ST[pos].s = 0;
	if(s == e) return ST[pos].f = A[s];
	int m = ( s + e ) / 2;
	return ST[pos].f = Min( init(pos*2,s,m) , init(pos*2+1,m+1,e) );
}
int update(int pos,int s,int e,int a,int b,int v)
{
	if(a <= s && e <= b) { ST[pos].s += v; return ST[pos].f += v; }
	if(a > e || b < s) return ST[pos].f;
	int m = ( s + e ) / 2;
	return ST[pos].f = Min( update(pos*2,s,m,a,b,v) , update(pos*2+1,m+1,e,a,b,v) ) + ST[pos].s;
}
int find(int pos,int s,int e,int t)
{
	if(s == e) return s;
	int m = ( s + e ) / 2;
	if(ST[pos*2+1].f + ST[pos].s + t == 0)
		return find(pos*2+1,m+1,e,t+ST[pos].s);
	return find(pos*2,s,m,t+ST[pos].s);
}
void solve()
{
	int i,t;
	scanf("%d",&N);

	FOR(i,1,N) scanf("%d",A+i);

	init(1,1,N);

	TFOR(i,N,1)
	{
		t = find(1,1,N,0);
		if(t == 1) break;
		if(t != N)
			update(1,1,N,t+1,N,-1);
		update(1,1,N,t,t,INF);
	}
	printf("%d\n" , i );
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
