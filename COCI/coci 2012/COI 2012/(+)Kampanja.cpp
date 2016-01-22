#include <iostream>
#include <cstdio>
#include <vector>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define MAXN 100
using namespace std;
vector < int > G[MAXN+5];
int M,N,res;
bool hash[MAXN+5],hash2[MAXN+5];
inline void rec2(int x,int s)
{
	if(s >= res) return;
	if(x == 1)
	{
		res = s;
		return;
	}
	register vector < int > :: iterator it;
	for(it = G[x].begin(); it != G[x].end(); ++it)
		if(!hash2[*it])
		{
			hash2[*it] = true;
			rec2(*it,s+!hash[*it]);
			hash2[*it] = false;
		}
}
inline void rec(int x,int s)
{
	if(s >= res) return;
	if(x == 2) { rec2(2,s); return; }
	register vector < int > :: iterator it;
	for(it = G[x].begin(); it != G[x].end(); ++it)
		if(!hash[*it])
		{
			hash[*it] = true;
			rec(*it,s+1);
			hash[*it] = false;
		}
}
inline void solve()
{
	register int a,b,i;
	scanf("%d %d",&N,&M);
	res = N;
	FOR(i,1,M)
	{
		scanf("%d %d",&a,&b);
		G[a].push_back(b);
	}
	rec(1,0);
	printf("%d\n",res);
}
int main()
{
	solve();
	return 0;
}
