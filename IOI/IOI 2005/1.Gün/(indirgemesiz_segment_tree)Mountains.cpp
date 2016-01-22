#include <algorithm>
#include <cstdio>
#include <iostream>
#include <map>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define MAXQ 100005
using namespace std;
map < long long , long long > mp;
class query
{
	public:
		long long a,b;
		long long v;
		char type;
}query[MAXQ];
class KD
{
	public:
		long long leftmax , sum , value;
		KD() { leftmax = sum = 0; value = -1; }
		KD set(long long a,long long b,long long c) { leftmax = a; sum = b; value = c; return *this; }

}ST[8*MAXQ];
inline long long Max( long long a , long long b ) { return a > b ? a : b; }
inline long long Min( long long a , long long b ) { return a < b ? a : b; }
long long K,N,Q;
long long B[2*MAXQ];
long long find(long long pos,long long s,long long e,long long h)
{
	if(h >= ST[pos].leftmax) return B[e];

	if(ST[pos].value != -1)
		return B[s-1] + h / ST[pos].value;

	long long m = ( s + e ) >> 1;
	long long sol = (pos << 1) + 1;
	long long sag = sol + 1;

	if(ST[sol].leftmax > h) return find(sol,s,m,h);
	return find(sag,m+1,e,h - ST[sol].sum);
}
void update(long long pos,long long s,long long e,long long a,long long b,long long v)
{
	if(a > e || b < s) return;
	if(a <= s && e <= b)
	{
		ST[pos].sum = (B[e] - B[s-1]) * v;
		ST[pos].leftmax = Max( ST[pos].sum , 0 );
		ST[pos].value = v;
		return;
	}
	long long m = ( s + e ) >> 1;
	long long sol = (pos << 1) + 1;
	long long sag = sol + 1;
	if(ST[pos].value != -1)
	{
		update( sol , s , m , s , m , ST[pos].value );
		update( sag , m+1,e , m+1,e , ST[pos].value );
		ST[pos].value = -1;
	}

	update(sol,s,m,a,b,v);
	update(sag,m+1,e,a,b,v);

	ST[pos].sum = ST[sol].sum + ST[sag].sum;
	ST[pos].leftmax = Max( ST[sol].leftmax , ST[sol].sum + ST[sag].leftmax );
}
void solve()
{
	long long v;
	long long a,b,i;
	char k;
	scanf("%lld",&N);
	while(1)
	{
		scanf(" %c" , &query[++Q].type);
		if(query[Q].type == 'I')
		{
			scanf("%lld %lld %lld",&query[Q].a,&query[Q].b,&query[Q].v);
			query[Q].a--;
			B[K++] = query[Q].a;
			B[K++] = query[Q].b;
		}
		else if(query[Q].type == 'Q')
			scanf("%lld",&query[Q].v);
		else break;
	}
	sort(B,B+K);
	K = unique(B,B+K) - B;

	FOR(i,1,Q-1)
		if(query[i].type == 'I')
			update(0,0,K-1 , lower_bound(B,B+K,query[i].a) - B + 1 , lower_bound(B,B+K,query[i].b) - B , query[i].v );
		else
			printf("%lld\n" , find(0,0,K-1,query[i].v) );
}
int main()
{
	solve();
	return 0;
}
