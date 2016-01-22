#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#define FOR(_i,__a,___b) for(_i=__a; _i<=___b; _i=_i+1)
#define f first
#define s second
using namespace std;
vector <int> yol,maxiyol;
vector < pair<int,int> > V[100005];
int maxi,N,S;
int d[10005];
bool visited[10005];
void dfs(int x,int s)
{
	yol.push_back(x);
	visited[x]=true;
	if(s>maxi) { maxi=s; maxiyol=yol; }
	for(vector< pair<int,int> > :: iterator it=V[x].begin(); it!=V[x].end(); ++it)
		if(!visited[it->f])
			dfs(it->f,s+it->s);
	yol.pop_back();
}
void dfs2(int x,int s)
{
	visited[x]=true;
	maxi=max(maxi,s);
	for(vector< pair<int,int> > :: iterator it=V[x].begin(); it!=V[x].end(); ++it)
		if(!visited[it->f])
			dfs(it->f,s+it->s);
}
void solve()
{
	int i,k,s,t=0,x,y;
	vector < pair<int,int> > :: iterator it;
	cin >> N >> S;
	FOR(i,1,N-1)
	{
		cin >> x >> y >> s;
		t+=s;
		V[x].push_back(make_pair(y,s));
		V[y].push_back(make_pair(x,s));
	}
	dfs(S,0);
	FOR(i,1,N) visited[i]=false;
	k=maxiyol.size()-2;
	FOR(i,0,k)
	{
		x=maxiyol[i];
		for(it=V[x].begin(); it!=V[x].end(); ++it)
			if(it->f==maxiyol[i+1])
				it->s*=-1;
	}
	t=2*t-maxi;
	maxi=0;
	dfs2(S,0);
	t=t-maxi;
	cout << t << endl;
}
int main()
{
	solve();
	return 0;
}
