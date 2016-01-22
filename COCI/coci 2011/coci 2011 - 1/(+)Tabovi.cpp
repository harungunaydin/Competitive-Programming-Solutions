#include <cmath>
#include <algorithm>
#include <cstdio>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define TFOR(i,a,b) for(i=a; i>=b; i--)
#define f first
#define s second
#define all(x) x.begin(),x.end()
#define MAXN 1005
using namespace std;
typedef pair < int , int > pii;
pii ST[4*MAXN];
int N;
int A[MAXN];
pii init(int pos,int s,int e)
{
	if(s == e) return ST[pos] = make_pair( abs( A[s] ) , s );
	int m = ( s + e ) >> 1;
	int sol = pos << 1;
	int sag = sol | 1;
	pii p1 = init(sol,s,m);
	pii p2 = init(sag,m+1,e);
	return ST[pos] = (p1.f < p2.f) ? p1 : p2;
}
pii find(int pos,int s,int e,int a,int b)
{
	if(a > e || b < s) return make_pair(1000,0);
	if(a <= s && e <= b) return ST[pos];
	int m = ( s + e ) >> 1;
	int sol = pos << 1;
	int sag = sol | 1;
	pii p1 = find(sol,s,m,a,b);
	pii p2 = find(sag,m+1,e,a,b);
	return (p1.f < p2.f) ? p1 : p2;
}
int dq(int a,int b,int k)
{
	if(a > b) return 0;
	pii p = find(1,1,N,a,b);

	p.f -= k;

	return dq(a,p.s-1,k+p.f) + dq(p.s+1,b,k+p.f) + p.f;

}
void solve()
{
	int a,i,j,res(0);
	scanf("%d",&N);
	FOR(i,1,N)
		scanf("%d",A+i);
	FOR(i,1,N)
	{
		scanf("%d",&a);
		A[i] -= a;
	}

	init(1,1,N);

	FOR(i,1,N)
	{
		j = i;
		while( i <= N && ( A[i] < 0 ) == ( A[j] < 0 ) ) i++;
		i--;
		res += dq(j,i,0);
	}
	printf("%d\n" , res );
}
int main()
{
	solve();
	return 0;
}
