#include <iostream>
#include <cstdio>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define MOD 10007
using namespace std;
void solve()
{
	int N,a,i,res(1);
	scanf("%d",&N);
	if(!N) res = 0;
	while(N >= 2 && N%3)
	{
		N -= 2;
		res = ( res * 2 ) % MOD;
	}
	while(N && !(N%3))
	{
		N -= 3;
		res = ( res * 3 ) % MOD;
	}
	printf("%d\n" , res );
}
int main()
{
	solve();
	return 0;
}
