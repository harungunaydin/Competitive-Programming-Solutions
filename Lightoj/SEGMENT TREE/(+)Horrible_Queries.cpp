#include <iostream>
#include <cstdio>
#include <cstring>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define f first
#define s second
#define MAXN 100005
using namespace std;
typedef pair < long long , long long > pll;
pll ST[4*MAXN];
int N,Q;
long long update(int pos,int s,int e,int a,int b,long long v)
{
	if(a <= s && e <= b) { ST[pos].s += v; return ST[pos].f += (long long) (e - s + 1) * v; }
	if(a > e || b < s) return ST[pos].f;
	int m = ( s + e ) / 2;
	return ST[pos].f = update(pos*2,s,m,a,b,v) + update(pos*2+1,m+1,e,a,b,v) + (e - s + 1) * ST[pos].s;
}
long long find(int pos,int s,int e,int a,int b,long long t)
{
	if(a <= s && e <= b) return ST[pos].f + t * (long long)(e - s + 1);
	if(a > e || b < s) return 0;
	int m = ( s + e ) / 2;
	return find(pos*2,s,m,a,b,t+ST[pos].s) + find(pos*2+1,m+1,e,a,b,t+ST[pos].s);
}
void solve()
{
	memset( ST , 0 , sizeof ST );
	register int a,b,c,i;
	long long v;
	scanf("%d %d",&N,&Q);
	FOR(i,1,Q)
	{
		scanf("%d %d %d",&c,&a,&b);
		a++; b++;
		if(!c)
		{
			scanf("%lld",&v);
			update(1,1,N,a,b,v);
		}
		else
			printf("%lld\n" , find(1,1,N,a,b,0) );
	}
}
int main()
{
	register int T,i;
	scanf("%d",&T);
	FOR(i,1,T)
	{
		printf("Case %d:\n",i);
		solve();
	}
	return 0;
}
