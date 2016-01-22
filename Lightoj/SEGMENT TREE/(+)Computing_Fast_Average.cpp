#include <iostream>
#include <cstdio>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define f first
#define s second
#define MAXN 100001
using namespace std;
typedef pair < int , int > pii;
pii ST[4*MAXN];
int Q,N;
inline int gcd( int a , int b ) { return !b ? a : gcd(b,a%b); }
inline int update(int pos,int s,int e,int a,int b,int v)
{
	if(a > e || b < s) return ST[pos].f;
	register int m = ( s + e ) >> 1;
	if(a <= s && e <= b)
	{
		ST[pos] = make_pair( v * (e - s + 1) , v );
		return ST[pos].f;
	}
	else if(s != e && ST[pos].s != -1)
	{
		ST[pos<<1] 	= make_pair(ST[pos].s * (m - s + 1) , ST[pos].s );
		ST[(pos<<1)+1] = make_pair(ST[pos].s * (e - m) , ST[pos].s );
		ST[pos].s = -1;
	}
	return ST[pos].f = update(pos<<1,s,m,a,b,v) + update((pos<<1)+1,m+1,e,a,b,v);
}
inline int find(int pos,int s,int e,int a,int b)
{
	if(a > e || b < s) return 0;
	if(ST[pos].s != -1) return ST[pos].s * ( min(b,e) - max(a,s) + 1 );
	if(a <= s && e <= b) return ST[pos].f;
	register int m = ( s + e ) >> 1;
	return find(pos<<1,s,m,a,b) + find((pos<<1)+1,m+1,e,a,b);
}
void solve()
{
	pii tmp = make_pair(0,-1);
	register int a,b,c,i,g,t,v;
	scanf("%d %d",&N,&Q);
	FOR(i,1,4*MAXN-1) ST[i] = tmp;
	FOR(i,1,Q)
	{
		scanf("%d %d %d",&c,&a,&b);
		a++; b++;
		if(c == 1)
		{
			scanf("%d",&v);
			update(1,1,N,a,b,v);
		}
		else
		{
			t = find(1,1,N,a,b);
			a = b - a + 1;
			if(t%a)
			{
				g = gcd(t,a);
				printf("%d/%d\n" , t / g , a / g );
			}
			else
				printf("%d\n" , t / a );
		}
	}
}
int main()
{
	int T,i;
	scanf("%d",&T);
	FOR(i,1,T)
	{
		printf("Case %d:\n",i);
		solve();
	}
	return 0;
}
