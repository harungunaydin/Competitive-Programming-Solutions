#include <iostream>
using namespace std;
long long unsigned fib[100];
void solve()
{
	long long N,i;
	scanf("%lld",&N);
	fib[0]=fib[1]=1;
	for(i=2; fib[i-1]+fib[i-2]<=N; i++)
		fib[i]=fib[i-1]+fib[i-2];
	for(i--; i>=0; i--)
	{
		if(N>=fib[i]) N-=fib[i];
		if(!N) break;
	}
	printf("%lld\n",fib[i]);
}
int main()
{
	solve();
	return 0;
}
