#include <iostream>
#include <cstdio>
#include <vector>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define MAXN 5000
using namespace std;
vector < int > G[MAXN+5];
int N;
bool visited[MAXN+5];
bool dfs(int x)
{
	if(x == N) return true;
	if(visited[x]) return false;
	visited[x] = true;
	vector < int > :: iterator it;
	for(it = G[x].begin(); it != G[x].end(); ++it)
		if(dfs(*it))
				return true;
	return false;
}
void read()
{
	int a,i,j,s;
	scanf("%d",&N);
	FOR(i,1,N-1)
	{
		scanf("%d",&s);
		FOR2(j,s)
		{
			scanf("%d",&a);
			G[i].push_back(a);
		}
	}
}
int main()
{	
	read();
	int i,res(0);
	vector < int > :: iterator it;
	for(it = G[1].begin(); it != G[1].end(); ++it)
		res+=dfs(*it);
	printf("%d\n",res);
	return 0;
}
