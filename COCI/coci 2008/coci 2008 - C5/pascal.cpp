#include <iostream>
#include <cmath>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define all(x) x.begin(),x.end()
#define MAXN 
using namespace std;
int solve()
{
	int N,b,i;
	scanf("%d",&N);
	b = (int) sqrt(N);
	if(N == 1) return 0;
	FOR(i,2,b)
		if(!(N%i))
			break;
	if(i == b+1) return N-1;
	return N-(N/i);
}
int main()
{
	printf("%d\n",solve());
	return 0;
}
