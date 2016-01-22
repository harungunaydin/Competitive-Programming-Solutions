#include <iostream>
#include <cstdio>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
using namespace std;
long long hesapla(long long a,long long b,long long c,long long d,long long e)
{
	return max ( 0ll , (d*c+e-1) / e - (a*c)/b - 1);
}
void solve()
{
	long long A1,A2,B,C,D,E1,E2,i,res(0);
	cin >> B >> C >> D >> A1 >> A2 >> E1 >> E2;
	for(i = 1; i * E2 < C * E1 ; i++)
		res += hesapla(A1,A2,B,i,C) * hesapla(i,C,D,E1,E2);
	printf("%lld\n",res);
}
int main()
{
	solve();
	return 0;
}
