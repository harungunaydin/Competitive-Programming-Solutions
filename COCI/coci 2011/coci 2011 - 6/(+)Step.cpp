#include <algorithm>
#include <cstdio>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define TFOR(i,a,b) for(i=a; i>=b; i--)
#define all(x) x.begin(),x.end()
#define MAXN 200005
#define MAXT 525000
using namespace std;
class KD
{
	public:
		int maxi,mini,s;
		KD() { maxi = mini = s = 0; }

}ST[MAXT];
int N,Q;
char A[MAXN];
void init(int pos,int s,int e)
{
	ST[pos].mini = ST[pos].maxi = 1;

	if(s == e) return;

	int m = ( s + e ) >> 1;
	int sol = pos << 1;
	int sag = sol | 1;

	init(sol,s,m);
	init(sag,m+1,e);

}
int get(int pos,int s,int e,int a,int syc)
{
	if(a > e || a < s) return 0;
	if(s == e) return ST[pos].maxi + syc;
	int m = ( s + e ) >> 1;
	int sol = pos << 1;
	int sag = sol | 1;

	int t = get(sol,s,m,a,syc+ST[pos].s);
	if(t) return t;
	return get(sag,m+1,e,a,syc+ST[pos].s);

}
void update(int pos,int s,int e,int a,int b,int v)
{
	if(a > e || b < s) return;
	if(a <= s && e <= b)
	{
		ST[pos].mini += v;
		ST[pos].maxi += v;
		ST[pos].s += v;
		return;
	}

	int m = ( s + e ) >> 1;
	int sol = pos << 1;
	int sag = sol | 1;

	update(sol,s,m,a,b,v);
	update(sag,m+1,e,a,b,v);

	ST[pos].mini = min( ST[sol].mini , ST[sag].mini ) + ST[pos].s;
	ST[pos].maxi = max( ST[sol].maxi , ST[sag].maxi ) + ST[pos].s;

}
int find(int pos,int s,int e,int a,int syc)
{
	if(a > e || ST[pos].mini + syc != 1) return N + 1;

	if(s == e) return s;

	int m = ( s + e ) >> 1;
	int sol = pos << 1;
	int sag = sol | 1;
	int t = syc + ST[pos].s;

	if(a <= s)
		return (ST[sol].mini + t == 1) ? find(sol,s,m,a,t) : find(sag,m+1,e,a,t);

	int k = find(sol,s,m,a,t);
	if(k != N + 1) return k;
	return find(sag,m+1,e,a,t);

}
void update2(int x,int v)
{
	update(1,1,N,x,x, v - get(1,1,N,x,0) );
}
void solve()
{
	int a,i;
	scanf("%d %d",&N,&Q);
	init(1,1,N);

	A[0] = 2; A[N+1] = 3;

	while(Q--)
	{
		scanf("%d",&a);

		A[a] ^= 1;

		if(A[a] == A[a+1])
			update(1,1,N,a, find(1,1,N,a+1,0) - 1 , - get(1,1,N,a,0) );

		if(A[a] == A[a-1])
			update2(a,1);
		else
			update2( a , get(1,1,N,a-1,0) + 1 );

		if(A[a] != A[a+1])
			update(1,1,N,a+1, find(1,1,N,a+2,0) - 1  , get(1,1,N,a,0) );

		printf("%d\n" , ST[1].maxi );

	}
}
int main()
{
	solve();
	return 0;
}
