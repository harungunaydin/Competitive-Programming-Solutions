#include <iostream>
#include <algorithm>
#include <cstdio>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define f first
#define s second
#define MAXN 300000
#define MAXT 300000
#define MOD 1000000007
#define ll long long
using namespace std;
typedef pair < ll , ll > pii;
pii P[MAXN+5],ST[1200005];
ll N;
ll A[MAXN+5];
bool cmp( const pii &a , const pii &b)
{
	return (a.f < b.f || (a.f == b.f && a.s > b.s));
}
void indirge()
{
	ll i,j,s(0);
	sort(P+1,P+N+1,cmp);
	FOR(i,1,N) P[i] = make_pair(P[i].s,i);
	sort(P+1,P+N+1);
	FOR(i,1,N)
	{
		j = i;
		s++;
		while(P[i].f == P[j].f && i <= N) A[P[i++].s] = s;
		i--;
	}
}
pii find(ll pos,ll s,ll e,ll a,ll b)
{
	if(a > e || b < s) return pii(0,0);
	if(a <= s && e <= b) return ST[pos];
	ll m = (s + e)/2;
	pii t1 = find(pos*2,s,m,a,b) , t2 = find(pos*2+1,m+1,e,a,b);
	return make_pair( max( t1.f , t2.f) , (t1.f == t2.f) ? (t1.s + t2.s)%MOD : (t1.f > t2.f) ? t1.s%MOD : t2.s%MOD );
}
void update(ll pos,ll s,ll e,ll up,pii uv)
{
	if(up < s || e < up) return;
	if(uv.f > ST[pos].f) ST[pos] = uv;
	else if(uv.f == ST[pos].f) ST[pos].s = (ST[pos].s + uv.s)%MOD;
	ST[pos].s %= MOD;
	if(s == e) return;
	
	ll m = (s + e)/2;
	update(pos*2,s,m,up,uv);
	update(pos*2+1,m+1,e,up,uv);
}
void solve()
{
	ll i,j;
	pii a;
	scanf("%lld",&N);
	FOR(i,1,N)
		scanf("%lld %lld",&P[i].f,&P[i].s);
	indirge();
	update(1,0,MAXT,0,pii(0,1));
	FOR(i,1,N)
	{
		a = find(1,0,MAXT,0,A[i]-1);
		a.f++;
		update(1,0,MAXT,A[i],a);
	}
	printf("%lld\n%lld\n",ST[1].f,ST[1].s%MOD);
}
int main()
{
	solve();
	return 0;
}
