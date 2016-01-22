#include <iostream>
#include <cstdio>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define TFOR(i,a,b) for(i=a; i>=b; i--)
#define MAXN 1005
using namespace std;
typedef pair < int , int > pii;
void solve()
{
	int N,a,i,mini,x,t;
	scanf("%d",&N);
	scanf("%d",&t);
	x = t;
	mini = t;
	FOR(i,2,N)
	{
		scanf("%d",&a);
		x ^= a;
		t += a;
		if(a < mini) mini = a;
	}
	if(x) { printf("NO\n"); return; }
	printf("%d\n" , t - mini );
}
int main()
{
	freopen("inp","r",stdin);
	freopen("out","w",stdout);
	int T,i;
	scanf("%d",&T);
	FOR(i,1,T)
	{
		printf("Case #%d: ",i);
		solve();
	}
	return 0;
}
