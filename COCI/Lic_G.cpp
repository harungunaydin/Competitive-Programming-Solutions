#include <iostream>
#include <cstdio>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
using namespace std;
FILE *out;
inline void solve()
{
	register int N,a,bolen,i,j,k,maxi(0),s(0),res;
	scanf("%d",&N);
	FOR(i,1,N)
	{
		bolen = 0;
		if(i&1) { a = 3; k = 2; }
		else { a = 2; k = 1; }
		for(j = a; j*j <= i; j+=k)
			if(!(i%j))
				bolen+=2;
		if((j-k)*(j-k) == i) bolen--;
		if(bolen > maxi)
		{
			maxi = bolen;
			res = i;
		}
	}
	printf("%d\n",res);
}
int main()
{
	printf("\n");
	//solve();
	return 0;
}
