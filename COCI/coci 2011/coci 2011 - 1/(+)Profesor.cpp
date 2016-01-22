#include <algorithm>
#include <cstdio>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define TFOR(i,a,b) for(i=a; i>=b; i--)
#define f first
#define s second
#define all(x) x.begin(),x.end()
#define MAXN 100005
using namespace std;
typedef pair < int , int > pii;
pii P[MAXN];
int N;
void solve()
{
	int i,k,maxi,res1(0),res2,s;
	scanf("%d",&N);
	FOR(i,1,N)
		scanf("%d %d",&P[i].f,&P[i].s);
	FOR(k,1,5)
	{
		s = 0;
		FOR(i,1,N)
			maxi = max ( maxi , s = (P[i].f == k || P[i].s == k) ? s + 1 : 0 );
		if(maxi > res1)
		{
			res1 = maxi;
			res2 = k;
		}
	}
	printf("%d %d\n" , res1 , res2 );
}
int main()
{
	solve();
	return 0;
}
