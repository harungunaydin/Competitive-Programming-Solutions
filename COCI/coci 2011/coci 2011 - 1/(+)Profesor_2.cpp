#include <iostream>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define f first
#define s second
#define all(x) x.begin(),x.end()
#define MAXN 100000
using namespace std;
typedef pair <int,int> pii;
pii p[MAXN+5];
int N;
int hesapla(int x)
{
	int i,maxi(0),s(0);
	FOR(i,1,N)
	{
		s = (p[i].f == x || p[i].s == x) ? s+1 : 0;
		maxi = max(maxi,s);
	}
	return maxi;
}
void solve()
{
	int i,k,res(0),t;
	scanf("%d",&N);
	FOR(i,1,N)
		scanf("%d %d",&p[i].f,&p[i].s);
	FOR(i,1,5)
	{
		t = hesapla(i);
		if(t > res)
		{
			res = t;
			k = i;
		}
	}
	printf("%d %d\n",res,k);
}
int main()
{
	solve();
	return 0;
}
