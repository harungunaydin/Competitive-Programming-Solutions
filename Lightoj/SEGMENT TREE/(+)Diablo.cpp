#include <iostream>
#include <cstdio>
#include <cstring>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define f first
#define s second
#define MAXN 100005
#define MAXQ 50005
using namespace std;
typedef pair < int , int > pii;
inline int Max( int a , int b ) { return a > b ? a : b; }
pii ST[4*MAXN],Query[MAXQ];
int Q,N;
int A[MAXN+MAXQ];
int init(int pos,int s,int e)
{
	if(s == e) return ST[pos].f = s;
	int m = ( s + e ) / 2;
	return ST[pos].f = Max( init(pos*2,s,m) , init(pos*2+1,m+1,e) );
}
int find(int pos,int s,int e,int a,int b)
{
	if(a <= s && e <= b) return ST[pos].f;
	if(a > e || b < s) return 0;
	int m = ( s + e ) / 2;
	return Max( find(pos*2,s,m,a,b) , find(pos*2+1,m+1,e,a,b) ) + ST[pos].s;
}
int update(int pos,int s,int e,int a,int b,int v)
{
	if(a <= s && e <= b) { ST[pos].s += v; return ST[pos].f += v; }
	if(a > e || b < s) return ST[pos].f;
	int m = ( s + e ) / 2;
	return ST[pos].f = Max( update(pos*2,s,m,a,b,v) , update(pos*2+1,m+1,e,a,b,v) ) + ST[pos].s;
}
inline int bul(int a,int b) { return find(1,1,N,a,b); }
int BS(int bas,int son,int a)
{
	if(bas == son) return bas;
	int orta = ( bas + son ) / 2;
	if(bul(orta,orta) == a) return orta;
	return bul(bas,orta-1) >= a ? BS(bas,orta-1,a) : BS(orta+1,son,a);
}
void solve()
{
	int a,i,s,t;
	char c;
	FOR(i,1,3*N) ST[i].s = 0;
	scanf("%d %d",&N,&Q);
	FOR(i,1,N) scanf("%d",A+i);
	s = N;
	FOR(i,1,Q)
	{
		scanf(" %c %d",&c,&a);
		Query[i] = make_pair(c,a);
		if(c == 'a') A[++N] = a;
	}
	init(1,1,N);
	FOR(i,1,Q)
	{
		if(Query[i].f == 'a') { s++; continue; }
		if(Query[i].s > s) { printf("none\n"); continue; }
		s--;
		t = BS(1,N,Query[i].s);
		printf("%d\n" , A[t] );
		update(1,1,N, t , t , - find(1,1,N,t,t) );
		update(1,1,N, t+1 , N , -1 );
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
