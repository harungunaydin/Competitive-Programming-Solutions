#include <algorithm>
#include <cstdio>
#include <set>
#include <vector>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define f first
#define s second
#define MAXN 200005
using namespace std;
typedef pair < int , int > pii;
set < pii > st[MAXN];
pii P[MAXN] , Q[MAXN];
int K,N,T;
int B[MAXN] , C[MAXN] , ST[4*MAXN];
void ekle(int pos,int s,int e,int a,int v)
{
	if(a > e || a < s) return;

	ST[pos] = max( ST[pos] , v );

	if(s == e) return;

	int m = ( s + e ) >> 1;
	int sol = pos << 1;
	int sag = sol | 1;

	ekle(sol,s,m,a,v);
	ekle(sag,m+1,e,a,v);

}
int res;
int bul(int pos,int s,int e,int a,int k)
{
	if(a > e) return 0;

	if( ST[pos] < k ) return 0;

	if(s == e) return res = st[s].lower_bound( make_pair(k,0) )->s;

	int m = ( s + e ) >> 1;
	int sol = pos << 1;
	int sag = sol | 1;

	if(s >= a)
	{
		if( ST[sol] >= k )
			return bul(sol,s,m,a,k);
		else if( ST[sag] >= k)
			return bul(sag,m+1,e,a,k);
		return 0;
	}

	int t = bul(sol,s,m,a,k);
	if(t) return t;

	return bul(sag,m+1,e,a,k);

}
void solve()
{
	int i,j,k(0),s(0);
	char c;
	scanf("%d",&K);
	FOR(i,1,K)
	{
		scanf(" %c",&c);
		if(c == 'D')
		{
			B[++T] = i;
			C[i] = T;
			scanf("%d %d",&Q[i].f,&Q[i].s);
			P[++k] = make_pair( Q[i].s , i );
		}
		else
		{
			scanf("%d",&Q[i].f);
			Q[i].s = 0;
		}
	}

	sort( P+1,P+k+1 );

	FOR(i,1,k) // SORGULARI INDIRGE
	{
		s++;
		j = i;
		while(i <= k && P[i].f == P[j].f) Q[ P[i++].s ].s = s;
		i--;
	}

	N = s;

	FOR(i,1,K)
		if(Q[i].s)
		{
			ekle(1,1,N,Q[i].s,Q[i].f);
			st[ Q[i].s ].insert( make_pair(Q[i].f,i) );
		}
		else
		{
			int t = B[ Q[i].f ];

			res = 0;

			set < pii > :: iterator it = st[ Q[t].s ].lower_bound( make_pair(Q[t].f+1,0) );

			if( it != st[ Q[t].s ].end() )
				res = it->s;

			if(!res) bul(1,1,N,Q[t].s+1,Q[t].f);

			if(res) printf("%d\n" , C[res] );
			else printf("NE\n");
		}

}
int main()
{
	solve();
	return 0;
}






