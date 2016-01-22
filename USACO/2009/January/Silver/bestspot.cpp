//SORU 1174
//PROGRAM C++
#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define all(x) x.begin(),x.end()
#define INPUT "bestspot.in"
#define OUTPUT "bestspot.out"
#define MAXN 500
#define INFINITY 500000000
#define f first
#define s second
#define EKLE(x,s) pq.push(make_pair(-(s),x))
#define BAK(x,s) { x = pq.top().s; s = - pq.top().f; pq.pop(); }
using namespace std;
ifstream in(INPUT);
ofstream out(OUTPUT);
typedef pair<int,int> pii;
vector <pii> V[MAXN+5];
priority_queue <pii> pq;
int E,F,N;
int favori[MAXN+5];
void read()
{
	int a,b,c,i;
	in >> N >> F >> E;
	FOR(i,1,F)
		in >> favori[i];
	FOR(i,1,E)
	{
		in >> a >> b >> c;
		V[a].push_back(make_pair(b,c));
		V[b].push_back(make_pair(a,c));
	}
}
int dijkstra(int a)
{
	vector <pii> :: iterator it;
	int i,res=0,s,x;
	int d[MAXN+5];
	FOR(i,1,N)
		d[i] = INFINITY;
	d[a] = 0;
	EKLE(a,0);
	while(!pq.empty())
	{
		BAK(x,s);
		for(it = V[x].begin(); it!=V[x].end(); ++it)
			if(s + it->s < d[it->f])
			{
				d[it->f] = s + it->s;
				EKLE(it->f,s+it->s);
			}
	}
	FOR(i,1,F)
		res+=d[favori[i]];
	return res;
}
void solve()
{
	int a,i,mini = INFINITY,res;
	FOR(i,1,N)
	{
		a = dijkstra(i);
		if(a < mini)
		{
			mini = a;
			res = i;
		}
	}
	out << res << endl;
}
int main()
{
	read();
	solve();
	return 0;
}
