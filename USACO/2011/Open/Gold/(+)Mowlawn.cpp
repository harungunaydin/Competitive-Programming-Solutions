#include <iostream>
#include <cstdio>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define TFOR(i,a,b) for(i=a; i>=b; i--)
#define MAX(a,b) ( (a) > (b) ? (a) : (b) )
#define INF 2000000000000000ll
#define MAXN 100005
using namespace std;
int K,N;
long long DP[MAXN],MAX[MAXN],ST[4*MAXN],T[MAXN];
inline long long Max( long long a , long long b ) { return a > b ? a : b; }
long long init(int pos,int s,int e)
{
	if(s == e) return ST[pos] = T[s];
	int m = ( s + e ) / 2;
	return ST[pos] = Max( init(pos*2,s,m) , init(pos*2+1,m+1,e) );
}
long long update(int pos,int s,int e,int a,long long v)
{
	if(a < s || a > e) return ST[pos];
	if(s == e) return ST[pos] += v;
	int m = ( s + e ) / 2;
	return ST[pos] = Max( update(pos*2,s,m,a,v) , update(pos*2+1,m+1,e,a,v) );
}
long long find(int pos,int s,int e,int a,int b)
{
	if(a <= s && e <= b) return ST[pos];
	if(a > e || b < s) return -INF;
	int m = ( s + e ) / 2;
	return Max( find(pos*2,s,m,a,b) , find(pos*2+1,m+1,e,a,b) );
}
void solve()
{
	register int i,j;
	scanf("%d %d",&N,&K);
	FOR(i,1,N)
	{
		scanf("%lld",T+i);
		T[i] += T[i-1];
	}
	init(1,1,N);
	TFOR(i,N,1)
	{
		long long t = find(1,1,N,i,i+K-1);
		MAX[i] = MAX( MAX[i+1] , t - T[i-1] );
		update(1,1,N,i-2,MAX[i]);
	}
	printf("%lld\n" , MAX[1] );
}
int main()
{
	solve();
	return 0;
}
