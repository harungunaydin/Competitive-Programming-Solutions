#include <iostream>
#include <cstdio>
#include <cstring>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define TFOR(i,a,b) for(i=a; i>=b; i--)
#define MAXN 100001
using namespace std;
typedef pair < int , int > pii;
class interval
{
	public:
		int sifir,bir,iki;
		interval() { sifir = bir = iki = 0; }
		interval(int a,int b,int c) { sifir = a; bir = b; iki = c; }
		interval Swap(int x)
		{
			if(!(x%3)) return (*this);
			swap(iki,bir); swap(iki,sifir);
			return Swap(x-1);
		}
		interval operator + ( interval b )
		{
			b.sifir += sifir;
			b.bir += bir;
			b.iki += iki;
			return b;
		}
}ST[4*MAXN];
interval make_interval(int a,int b,int c) { interval I(a,b,c); return I; }
int N,Q;
int B[4*MAXN];
interval init(int pos,int s,int e)
{
	if(s == e) return ST[pos] = make_interval(1,0,0);
	int m = ( s + e ) / 2;
	return ST[pos] = init(pos*2,s,m) + init(pos*2+1,m+1,e);
}
interval update(int pos,int s,int e,int a,int b)
{
	if(a <= s && e <= b) { B[pos]++; return ST[pos].Swap(1); }
	if(a > e || b < s) return ST[pos];
	int m = ( s + e ) / 2;
	ST[pos] = update(pos*2,s,m,a,b) + update(pos*2+1,m+1,e,a,b);
	return ST[pos].Swap(B[pos]);
}
interval find(int pos,int s,int e,int a,int b,int t)
{
	if(a <= s && e <= b) { interval I = ST[pos]; return I.Swap(t); }
	if(a > e || b < s) return make_interval(0,0,0);
	int m = ( s + e ) / 2;
	return find(pos*2,s,m,a,b,t+B[pos]) + find(pos*2+1,m+1,e,a,b,t+B[pos]);
}
void solve()
{
	int a,b,c,i;
	scanf("%d %d",&N,&Q);
	init(1,1,N);
	FOR(i,1,Q)
	{
		scanf("%d %d %d",&c,&a,&b);
		if(c)
			printf("%d\n" , find(1,0,N-1,a,b,0).sifir );
		else
			update(1,0,N-1,a,b);
	}
}
int main()
{
	int T,i;
	scanf("%d",&T);
	FOR(i,1,T)
	{
		if(i != 1) memset( B , 0 , sizeof B );
		printf("Case %d:\n" , i );
		solve();
	}
	return 0;
}
