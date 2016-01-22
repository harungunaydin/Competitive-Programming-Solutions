#include <iostream>
#include <map>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define f first
#define s second
#define MAXN 100000
using namespace std;
map <double , long long> mpX,mpY;
pair <double , double> P[MAXN+5];
void solve()
{
	int N,i;
	long long res(0);
	scanf("%d",&N);
	FOR(i,1,N)
	{
		scanf("%lf %lf",&P[i].f,&P[i].s);
		mpX[P[i].f]++;
		mpY[P[i].s]++;
	}
	FOR(i,1,N)
		res+=(mpX[P[i].f]-1)*(mpY[P[i].s]-1);
	printf("%lld\n",res);
}
int main()
{
	solve();
	return 0;
}
