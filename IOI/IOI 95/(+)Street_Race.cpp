#include <iostream>
#include <algorithm>
#include <queue>
#include <set>
#include <vector>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,N) FOR(i,0,n-1)
#define MAXN 500
#define OO 100000
using namespace std;
vector <int> V,V2,temp1,temp2;
vector <int> G[MAXN+5];
int N,vis,vis2;
int visited[123123],visited2[123123];
bool reach(int a,int b,int c)
{
	vis++;
	queue <int> qx;
	vector <int> :: iterator it;
	int x;
	qx.push(a);
	visited[a] = vis;
	while(!qx.empty())
	{
		x = qx.front(); qx.pop();
		for(it = G[x].begin(); it!=G[x].end(); ++it)
			if(visited[*it] < vis && *it != c)
			{
				visited[*it] = vis;
				qx.push(*it);
				if(*it == b) return 1;
			}
	}
	return 0;
}
bool bfs(int a,int b,bool c)
{
	vis++;
	if(c) temp1.clear();
	else  temp2.clear();
	queue <int> qx;
	vector <int> :: iterator it;
	int x;
	qx.push(a);
	visited[a] = vis;
	while(!qx.empty())
	{
		x = qx.front(); qx.pop();
		if(c) temp1.push_back(x);
		else  temp2.push_back(x);
		for(it = G[x].begin(); it!=G[x].end(); ++it)
			if(visited[*it] < vis)
			{
				visited[*it] = vis;
				qx.push(*it);
			}
	}
	return 0;
}
bool control(int x)
{
	vector <int> :: iterator it,it2;
	for(it=temp1.begin(); it!=temp1.end(); ++it)
		for(it2=temp2.begin(); it2!=temp2.end(); ++it2)
			if(reach(*it,*it2,x) || reach(*it2,*it,x))
				return 0;
	return 1;
}
void solve()
{
	int a,i;
	while(1)
	{
		cin >> a;
		if(a == -1) break;
		while(a!=-2)
		{
			G[N].push_back(a);
			cin >> a;
		}
		N++;
	}
	FOR(i,1,N-2)
	{
		visited[i] = vis+1;
		if(!reach(0,N-1,OO)) V.push_back(i);
	}
	vector <int> :: iterator it,it2,it3;
	for(it = V.begin(); it!=V.end(); ++it)
	{
		visited[*it] = vis+1;
		bfs(0,*it,1);
		bfs(*it,N-1,0);
		if(control(*it)) V2.push_back(*it);
	}
	printf("%d",V.size());
	for(it = V.begin(); it!=V.end(); ++it)
		printf(" %d",*it);
	printf("\n%d",V2.size());
	for(it = V2.begin(); it!=V2.end(); ++it)
		printf(" %d",*it);
	printf("\n");
}
int main()
{
	solve();
	return 0;
}
