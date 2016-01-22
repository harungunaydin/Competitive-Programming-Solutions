#include <iostream>
#include <cstdio>
#include <vector>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define MAXN 1000
using namespace std;
vector < int > V[MAXN+5];
bool A[MAXN+5][MAXN+5];
void solve()
{
	register int M,N,a,b,i,j,k;
	register long long res(0),s;
	scanf("%d %d",&N,&M);
	FOR(i,1,M)
	{
		scanf("%d %d",&a,&b);
		V[a].push_back(b);
		A[a][b] = true;
	}
	vector < int > :: iterator it;
	FOR(i,1,N)
		if(V[i].size() > 1)
			FOR(j,i+1,N)
				if(V[j].size() > 1)
				{
					s = 0;
					for(it = V[j].begin(); it != V[j].end(); ++it)
						s+=A[i][*it];
					res+= (s*(s-1))/2;
				}
	printf("%lld\n",res);
}
int main()
{
	solve();
	return 0;
}
