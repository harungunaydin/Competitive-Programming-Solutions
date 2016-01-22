#include <iostream>
#include <cstdio>
#include <vector>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define MAXN 2000
using namespace std;
vector < int > G[MAXN+5],GT[MAXN+5];
int BH,N,SH,vis;
int A[MAXN+5],DP[MAXN+5],visited[MAXN+5];
inline int bul(int x)
{
	if(DP[x]) return DP[x];
	if(G[x].empty()) return DP[x] = 3;
	vector < int > :: iterator it;
	if(A[x] == 1)
	{
		for(it = G[x].begin(); it != G[x].end(); ++it)
			if(bul(*it) != 1)
				break;
		return DP[x] = (it == G[x].end()) ? 1 : 2;
	}
	else
	{
		for(it = G[x].begin(); it != G[x].end(); ++it)
			if(bul(*it) == 2)
				return DP[x] = 2;
		return DP[x] = 1;
	}
	return 0;
}
void solve()
{
	vector < int > :: iterator it;
	register int M,a,i,j,s;
	scanf("%d",&N);
	FOR(i,1,N)
	{
		scanf("%d",A+i);
		if(A[i] == 3) BH = i;
		if(A[i] == 4) SH = i;
	}
	FOR(i,1,N)
	{
		scanf("%d",&s);
		FOR2(j,s)
		{
			scanf("%d",&a);
			G[i].push_back(a);
			GT[a].push_back(i);
		}
	}
	DP[BH] = 1;
	DP[SH] = 2;
	for(it = GT[BH].begin(); it != GT[BH].end(); ++it)
		if(A[*it] == 1)
			DP[*it] = 1;
	for(it = GT[SH].begin(); it != GT[SH].end(); ++it)
		if(A[*it] == 2)
			DP[*it] = 2;
			
	scanf("%d",&M);
	FOR(i,1,M)
	{
		scanf("%d",&a);
		printf("%d ", bul(a) );
	}
}
int main()
{
	solve();
	return 0;
}
