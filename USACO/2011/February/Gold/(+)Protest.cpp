#include <iostream>
#include <algorithm>
#include <cstdio>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define MOD 1000000009ll
#define MAXN 100005
#define MAXL 1000000000
using namespace std;
int M,N;
long long A[MAXN],T[MAXN],ST[4*MAXN];
void update(int pos,int s,int e,int a,long long v)
{
	if(a < s || a > e) return;
	ST[pos] = ( ST[pos] + v ) % MOD;
	if(s == e) return;
	int m = ( s + e ) / 2;
	update(pos*2,s,m,a,v);
	update(pos*2+1,m+1,e,a,v);
}
long long find(int pos,int s,int e,int a,int b)
{
	if(a <= s && e <= b) return ST[pos];
	if(a > e || b < s) return 0;
	int m = ( s + e ) / 2;
	return ( find(pos*2,s,m,a,b) + find(pos*2+1,m+1,e,a,b) ) % MOD;
}
int bul(long long a) { return lower_bound(A+1,A+M+1,a) - A; }
void solve()
{
	long long t;
	int i,j;
	scanf("%d",&N);
	M = N;
	FOR(i,1,N)
	{
		scanf("%lld",T+i);
		T[i] += T[i-1];
	}
	FOR(i,1,N)
	{
		T[i] += MAXL;
		A[i] = T[i];
	}
	A[++M] = MAXL;
	sort(A+1,A+M+1);
	M = unique(A+1,A+M+1) - A - 1;
	update(1,1,M,bul(MAXL),1ll);
	FOR(i,1,N)
	{
		t = find(1,1,M,1,bul(T[i]));
		update( 1,1,M , bul(T[i]) , find(1,1,M,1,bul(T[i])) );
	}
	printf("%lld\n" , t );
}
int main()
{
	solve();
	return 0;
}
