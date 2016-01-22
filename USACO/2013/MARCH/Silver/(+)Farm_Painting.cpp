#include <iostream>
#include <algorithm>
#include <cstdio>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define T 1000000
#define MAXN 50001
using namespace std;
class bisi
{
	public:
		int k,x,y1,y2;
		bisi() { x = y1 = y2 = k = 0; }
		void set(int a,int b,int c,int t) { x = a; y1 = b; y2 = c; k = t; }
}A[2*MAXN];
inline bool cmp( const bisi &a , const bisi &b ) { return a.x < b.x || (a.x == b.x && a.k < b.k); }
int M,N;
int ST[4*T+5];
void update(int pos,int s,int e,int a,int b,int v)
{
	if(a > e || b < s) return;
	if(a <= s && e <= b) { ST[pos] += v; return; }
	int m = ( s + e ) / 2;
	update(pos*2,s,m,a,b,v);
	update(pos*2+1,m+1,e,a,b,v);
}
int find(int pos,int s,int e,int a)
{
	if(a < s || a > e) return 0;
	if(s == e) return ST[pos];
	int m = ( s + e ) / 2;
	return find(pos*2,s,m,a) + find(pos*2+1,m+1,e,a) + ST[pos];
}
void solve()
{
	int i,res(0),x1,x2,y1,y2;
	scanf("%d",&M);
	FOR(i,1,M)
	{
		scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
		A[++N].set(x1,y1,y2,1);
		A[++N].set(x2,y1,y2,-1);
	}
	sort(A+1,A+N+1,cmp);
	FOR(i,1,N)
	{
		if(A[i].k == 1 && !find(1,1,T,A[i].y1)) res++;
		update(1,1,T,A[i].y1+1,A[i].y2,A[i].k);
	}
	printf("%d\n" , res );
}
int main()
{
	freopen("painting.in","r",stdin);
	freopen("painting.out","w",stdout);
	solve();
	return 0;
}
