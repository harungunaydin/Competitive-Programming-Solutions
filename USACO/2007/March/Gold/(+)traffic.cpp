#include <iostream>
#include <algorithm>
#include <cstdio>
#include <queue>
#include <vector>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define MAXN 5005
using namespace std;
typedef pair < int , int > pii;
queue < int > Q;
vector < pii > E;
vector < int > G[MAXN],GT[MAXN];
int M,N;
int B[MAXN],C[MAXN],D[MAXN],In[MAXN];
void solve()
{
	vector < int > :: iterator it;
	int a,b,i,j,res(0),x;
	scanf("%d %d",&N,&M);
	FOR(i,1,M)
	{
		scanf("%d %d",&a,&b);
		G[a].push_back(b);
		GT[b].push_back(a);
		E.push_back(make_pair(a,b));
		In[b]++;
		D[a]++;
	}
	FOR(i,1,N)
		if(!In[i])
		{
			Q.push(i);
			B[i] = 1;
		}
	while(!Q.empty())
	{
		x = Q.front(); Q.pop();
		for(it = G[x].begin(); it != G[x].end(); ++it)
		{
			B[*it] += B[x];
			if(!(--In[*it]))
				Q.push(*it);
		}
	}
	Q.push(N);
	C[N] = 1;
	while(!Q.empty())
	{
		x = Q.front(); Q.pop();
		for(it = GT[x].begin(); it != GT[x].end(); ++it)
		{
			C[*it] += C[x];
			if(!(--D[*it]))
				Q.push(*it);
		}
	}
	vector < pii > :: iterator it2;
	for(it2 = E.begin(); it2 != E.end(); ++it2)
		res = max( res , B[it2->first] * C[it2->second] );
	printf("%d\n" , res);
}
int main()
{
	solve();
	return 0;
}
