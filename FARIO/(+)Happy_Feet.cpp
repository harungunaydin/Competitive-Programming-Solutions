#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define MAX(a,b) ( (a) > (b) ? (a) : (b) )
#define f first
#define s second
#define MAXM 200005
#define MAXN 1005
using namespace std;
typedef pair < int , int > pii;
class edge
{
	public:
		int a,b;
		long long c;
		edge() { a = b = c = 0; }
		void set(int x,int y,int z) { a = x; b = y; c = z; }
}E[MAXM];
inline bool cmp( const edge &a , const edge &b) { return a.c < b.c; }
int M,N,s;
long long DP[MAXN],TMP_DP[MAXN];
void solve()
{
	int a,b,c,i,j,k;
	scanf("%d %d",&N,&M);
	FOR(i,1,M)
	{
		scanf("%d %d %d",&a,&b,&c);
		E[i].set(a,b,c);
		E[M+i].set(b,a,c);
	}
	M <<= 1;
	sort(E+1,E+M+1,cmp);
	FOR(i,1,M)
	{
		k = i;
		while(i <= M && E[i].c == E[k].c) i++;
		i--;
		FOR(j,k,i) TMP_DP[E[j].a] = DP[E[j].a];
		FOR(j,k,i)
			DP[E[j].b] = MAX( DP[E[j].b] , TMP_DP[E[j].a] + E[j].c );
	}
	long long res(0);
	FOR(i,1,N)
		res = MAX( res , DP[i] );
	printf("%lld\n" , res );
}
int main()
{
	solve();
	return 0;
}
