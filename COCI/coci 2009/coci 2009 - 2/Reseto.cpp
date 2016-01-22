#include <iostream>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define all(x) x.begin(),x.end()
#define MAXN 1000
using namespace std;
int ASAL[2*MAXN+5];
int solve()
{
	int K,N,i,j;
	scanf("%d %d",&N,&K);
	FOR(i,2,N)
		if(!ASAL[i])
			for(j=i; j<=N; j+=i)
				if(!ASAL[j])
				{
					ASAL[j] = true;
					if(!(--K)) return j;
				}
}
int main()
{
	printf("%d\n",solve());
	return 0;
}
