#include <iostream>
#include <vector>
#include <queue>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define EKLE(x,s) { qx.push(x); qs.push(s); }
#define BAK(x,s) { x=qx.front(); s=qs.front(); qx.pop(); qs.pop(); }
using namespace std;
queue <int> qx,qs;
vector <int> V[5005],temp,yol;
int K,N,a;
bool flag;
bool B[5005],C[5005],visited[5005];
void dfs(int x)
{
	if(flag) return;
	temp.push_back(x);
	if(x==a)
	{
		yol=temp;
		flag=true;
		return;
	}
	vector <int> :: iterator it;
	for(it=V[x].begin(); it!=V[x].end(); ++it)
		dfs(*it);
	temp.pop_back();
}
void clear()
{
	int i;
	while(!qx.empty()) { qx.pop(); qs.pop(); }
	FOR(i,1,N) visited[i]=false;
}
int kaydir(int b)
{
	int i,s,x;
	EKLE(b,0);
	vector <int> :: iterator it;
	while(!qx.empty())
	{
		BAK(x,s);
		if(!B[x] && !C[x]) { B[b]=false; B[x]=true; clear(); return s; }
		if(visited[x]) continue;
		visited[x]=true;
		for(it=V[x].begin(); it!=V[x].end(); ++it)
			if(!visited[*it] && *it!=a)
				EKLE(*it,s+1);
	}
	return -1;
}
void read()
{
	int i,j,x,s;
	cin >> N >> a >> K;
	FOR(i,1,N)
	{
		cin >> s;
		FOR(j,1,s)
		{
			cin >> x;
			V[i].push_back(x);
		}
	}
	FOR(i,1,K)
	{
		cin >> x;
		B[x]=true;
	}
}
int solve()
{
	int i,b,t=0;
	for(i=yol.size()-1; i; i--)
		C[yol[i]]=true;
	for(i=yol.size()-1; i; i--)
		if(B[yol[i]])
		{
			b=kaydir(yol[i]);
			if(b==-1) return -1;
			t+=b;
		}
	return t;
}
int main()
{
	read();
	dfs(1);
	int a=solve();
	(a!=-1)? cout << a : cout << "not solvable";
	cout << endl;
	return 0;
}
