#include <iostream>
#include <queue>
#include <vector>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define EKLE(x,s) Q.push(make_pair(-s,x))
#define BAK(x,s) { x=Q.top().second; s=-Q.top().first; Q.pop(); }
using namespace std;
priority_queue < pair<int,int> > Q;
vector <int> V[1005];
vector <int> :: iterator it;
bool visited[1005];
int K,N;
int hesapla(int x,int y,int t)
{
	int a,b,c,isup=!((t/(x-y))&1);
	if(y>x)
	{
		a=y-x;
		b=t%(2*a);
		c=t%a;
		if(!b) return a;
		if(b==a) return 2*a;
		return (isup)? 3*a-c : 2*a-c;
	}
	a=x-y;
	b=t%(2*a);
	c=t%a;
	if(!b) return 2*a;
	if(b==a) return a;
	return (isup)? 2*a-c: 3*a-c;
}
int solve()
{
	int K,N,i,x,s;
	cin >> K >> N;
	FOR(i,1,N)
	{
		cin >> x >> s;
		V[x].push_back(s);
		V[s].push_back(x);
	}
	EKLE(1,0);
	while(!Q.empty())
	{
		BAK(x,s);
		if(x==K) return s*5;
		if(visited[x]) continue;
		visited[x]=true;
		for(it=V[x].begin(); it!=V[x].end(); ++it)
			if(!visited[*it])
				EKLE(*it,(s+hesapla(x,*it,s)));
	}
}
int main()
{
	cout << solve() << endl;
	return 0;
}
