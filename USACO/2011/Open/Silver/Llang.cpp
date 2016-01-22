#include <iostream>
#include <vector>
#define FOR(i,a,b) for(i=a; i<=b; i++)
using namespace std;
vector <int> V[50005];
vector <int> :: iterator it;
bool hash[50005],hash2[50005];
void dfs(int x)
{
	hash[x]=true;
	register vector <int> :: iterator it;
	for(it=V[x].begin(); it!=V[x].end(); ++it)
		if(!hash[*it])
			dfs(*it);
}
void solve()
{
	register int M,N,a,i,j,maxi=0,s,x;
	scanf("%d %d",&M,&N);
	FOR(i,1,N)
	{
		scanf("%d",&s);
		a=i + 35000;
		hash2[a]=true;
		FOR(j,1,s)
		{
			scanf("%d",&x);
			maxi>?=x;
			hash2[x]=true;
			V[a].push_back(x);
			V[x].push_back(a);
		}
	}
	maxi>?=N+35000;
	s=0;
	FOR(i,1,maxi)
		if(hash2[i] && !hash[i] && ++s)
			dfs(i);
	printf("%d\n",s - 1);
}
int main()
{
	solve();
	return 0;
}
