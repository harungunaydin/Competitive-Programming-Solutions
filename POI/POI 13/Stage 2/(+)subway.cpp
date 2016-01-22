#include <algorithm>
#include <cstdio>
#include <vector>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define MAXN 1000005
using namespace std;

int B[MAXN] , C[MAXN] , Q[MAXN];

void solve()
{
	int L,N,a,b,i,res(0),sz(0),sz2;
	scanf("%d %d",&N,&L);
	FOR(i,1,N-1)
	{
		scanf("%d %d",&a,&b);
		B[a]++;
		B[b]++;
		C[a] += b;
		C[b] += a;
	}

	FOR(i,1,N)
		if(B[i] == 1)
			Q[++sz] = i;

	while(sz)
	{
		res += min( L*2 , sz );
		sz2 = 0;
		FOR(i,1,sz)
		{
			a = Q[i];
			C[ C[a] ] -= a;
			if(--B[ C[a] ] == 1)
				Q[++sz2] = C[a];
		}
		sz = sz2;
	}

	printf("%d\n" , res );

}
int main()
{
	solve();
	return 0;
}
