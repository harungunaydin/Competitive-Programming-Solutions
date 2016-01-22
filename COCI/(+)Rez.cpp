#include <iostream>
#include <cstdio>
#define FOR(i,a,b) for(i=a; i<=b; i++)
using namespace std;
void solve()
{
	int K,N,i(1),k(1),s(2);
	scanf("%d",&K);
	while(s < K)
	{
		i++;
		s+=i;
		k++;
	}
	k = (K == 1) ? 0 : k;
	printf("%d\n",k);
	FOR(i,1,k)
		printf("%d %d %d %d\n",5000 - i - 1, -5000 , -5000 , -5000 + i + 2 );
}
int main()
{
	solve();
	return 0;
}
