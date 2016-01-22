#include <iostream>
#include <vector>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
using namespace std;
vector < long long > V;
vector < long long > :: iterator it;
bool kontrol(int a)
{
	for(it = V.begin(); it!=V.end(); ++it)
		if(!(a%(*it)))
			return 0;
	return 1;
}
void solve()
{
	long long N,a,i;
	scanf("%lld",&N);
	scanf("%lld",&a);
	FOR(i,2,N)
	{
		scanf("%lld",&a);
		a--;
		if(kontrol(a))
			V.push_back(a);
	}
	printf("%d\n",V.size());
}
int main()
{
	solve();
	return 0;
}
