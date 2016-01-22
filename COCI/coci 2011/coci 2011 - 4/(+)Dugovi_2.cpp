#include <iostream>
#include <queue>
#include <vector>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define INF 2000000000
#define MAXN 200000
using namespace std;
queue <int> Q;
vector <int> G[MAXN+5];
int N,S,vis;
int A[MAXN+5],B[MAXN+5],C[MAXN+5];
int In[MAXN+5],visited[MAXN+5];
bool hash[MAXN+5];
void rec(int x)
{
	if(visited[x] == vis)
	{
		int i = A[x];
		G[++S].push_back(x);
		while(i != x)
		{
			G[S].push_back(i);
			i = A[i];
		}
		return;
	}
	visited[x] = vis;
	if(A[x] && (!visited[A[x]] || visited[A[x]] == vis))
		rec(A[x]);
}
void find_loops()
{
	int a,i,k,res(0),t,x;
	
	FOR(i,1,N)
	 	if(!visited[i])
			++vis,rec(i); //FIND LOOPS 
	
	vector <int> :: iterator it;
	FOR(i,1,S)
		for(it = G[i].begin(); it!=G[i].end(); ++it)
			hash[*it] = true;//HASH THEM
	FOR(i,1,N)
		if(!In[i])
			Q.push(i);
	while(!Q.empty())
	{
		x = Q.front(); Q.pop();
		t = A[x];
		if(C[x]>=B[x])
		{
			C[x]-=B[x];
			C[t]+=B[x];
		}
		else
		{
			res+=B[x]-C[x];
			C[t]+=B[x];
			C[x] = 0;
		}
		if(!(--In[t]))
		{
			Q.push(t);
			hash[t] = true;
		}
	}
	int maxi;
	FOR(i,1,S)
	{
		maxi = -INF;
		for(it = G[i].begin(); it!=G[i].end(); ++it)
			if(C[*it] - B[*it] > maxi)
			{
				maxi = C[*it] - B[*it];
				k = *it;
			}
		a = k;
		while(1)
		{
			t = A[k];
			if(C[k] >= B[k])
			{
				C[k]-=B[k];
				C[t]+=B[k];
			}
			else
			{
				res+=B[k]-C[k];
				C[t]+=B[k];
			}
			k = t;
			if(k == a) break;
		}
	}
	printf("%d\n",res);
}
void solve()
{
	int i;
	scanf("%d",&N);
	FOR(i,1,N)
	{
		scanf("%d %d",A+i,B+i);
		In[A[i]]++;
	}
	find_loops();
}
int main()
{
	solve();
	return 0;
}

