#include <algorithm>
#include <cstdio>
#include <iostream>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define MIN(a,b) ( (a) < (b) ? (a) : (b) )
#define MAX(a,b) ( (a) > (b) ? (a) : (b) )
#define f first
#define s second
#define MAXN 100005
using namespace std;
typedef pair < int , int > pii;
inline int Max( int a , int b ) { return a > b ? a : b; }
class uclu
{
	public:
		int f,s,x;
		uclu() { f = s = x = 0; }
}A[MAXN];
inline bool cmp1( const uclu &a , const uclu &b)
{
	if(a.f < b.f) return 1;
	if(a.f > b.f) return 0;
	return a.x > b.x;
}
inline bool cmp2( const uclu &a , const uclu &b)
{
	if(a.f > b.f) return 1;
	if(a.f < b.f) return 0;
	return a.x > b.x;
}
pii ST[4*MAXN];
int N;
int K[MAXN];
void init(int pos,int s,int e)
{
	ST[pos] = make_pair(N+1,0);
	if(s == e) return;
	int m = ( s + e ) >> 1;
	init(pos<<1,s,m);
	init((pos<<1)+1,m+1,e);
}
pii update(int pos,int s,int e,int a,int v)
{
	if(a > e || a < s) return ST[pos];
	if(s == e) return ST[pos] = make_pair(v,v);
	int m = ( s + e ) >> 1;
	pii p1 = update(pos<<1,s,m,a,v);
	pii p2 = update((pos<<1)+1,m+1,e,a,v);
	return ST[pos] = make_pair( MIN(p1.f , p2.f) , MAX(p1.s , p2.s) );
}
pii find(int pos,int s,int e,int a,int b)
{
	if(a > e || b < s) return make_pair(N+1,0);
	if(a <= s && e <= b) return ST[pos];
	int m = ( s + e ) >> 1;
	pii p1 = find(pos<<1,s,m,a,b);
	pii p2 = find((pos<<1)+1,m+1,e,a,b);
	return make_pair( MIN(p1.f , p2.f) , MAX(p1.s , p2.s) );
}
int bul(int pos,int s,int e,int k,int b)
{
	if(!ST[pos].s) return 0;
	if(s > k) return 0;
	if(s == e) return (ST[pos].s && ST[pos].s != b) ? s : 0;
	int m = ( s + e ) >> 1;
	int sol = pos << 1;
	int sag = sol | 1;
	if(e <= k)
	{
		if(ST[sag].s && ST[sag].f != ST[sag].s) return bul(sag,m+1,e,k,b);
		if(ST[sag].f == ST[sag].s && ST[sag].f != b) return bul(sag,m+1,e,k,b);
		return bul(sol,s,m,k,b);
	}
	return Max( bul(sol,s,m,k,b) , bul(sag,m+1,e,k,b) );
}
pii init2(int pos,int s,int e)
{
	if(s == e) return ST[pos] = make_pair(K[s],s);
	int m = ( s + e ) >> 1;
	int sol = pos << 1;
	int sag = sol | 1;
	pii p1 = init2(sol,s,m);
	pii p2 = init2(sag,m+1,e);
	return ST[pos] = (p1.f > p2.f) ? p1 : p2;
}
pii find_Max(int pos,int s,int e,int a,int b)
{
	if(a > e || b < s) return make_pair(0,0);
	if(a <= s && e <= b) return ST[pos];
	int m = ( s + e ) >> 1;
	int sol = pos << 1;
	int sag = sol | 1;
	pii p1 = find_Max(sol,s,m,a,b);
	pii p2 = find_Max(sag,m+1,e,a,b);
	return p1.f > p2.f ? p1 : p2;
}
bool solve()
{
	int Q,a,b,i;
	scanf("%d",&N);
	FOR(i,1,N)
	{
		scanf("%d %d" , &A[i].f , &A[i].s );
		A[i].x = i;
	}

	sort(A+1,A+N+1,cmp1);
	init(1,1,N);

	FOR(i,1,N)
	{
		if(A[i].x > 1)
			K[A[i].x] = bul( 1 , 1 , N , A[i].x - 1 , A[i].s );
		update(1,1,N , A[i].x , A[i].s );
	}
	
	sort(A+1,A+N+1,cmp2);
	init(1,1,N);
	FOR(i,1,N)
	{
		if(A[i].x > 1)
			K[A[i].x] = Max( K[A[i].x] , bul(1 , 1 , N , A[i].x - 1 , A[i].s) );
		update(1,1,N , A[i].x , A[i].s );
	}
	init2(1,1,N);

	scanf("%d",&Q);

	int a1,a2,k1,k2;
	FOR(i,1,Q)
	{
		scanf("%d %d",&a,&b);
		pii p = find_Max(1,1,N , a , b );
		if(p.f >= a) printf("%d %d\n" , p.f , p.s );
		else printf("0 0\n");
	}
}
int main()
{
	solve();
	return 0;
}
