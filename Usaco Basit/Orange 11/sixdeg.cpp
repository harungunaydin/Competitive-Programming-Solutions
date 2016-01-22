//SORU 414
//PROGRAM C++
#include <iostream>
#include <fstream>
#include <algorithm>
#include <queue>
#include <vector>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define all(x) x.begin(),x.end()
#define INPUT "sixdeg.in"
#define OUTPUT "sixdeg.out"
#define MAXN 1000
#define EKLE(x,s) { qx.push(x); qs.push(s); visited[x] = true; }
#define BAK(x,s)  { x = qx.front(); s = qs.front(); qx.pop(); qs.pop(); }
using namespace std;
ifstream in(INPUT);
ofstream out(OUTPUT);
queue <int> qx,qs;
vector <int> G[MAXN+5];
int res[MAXN+5];
bool visited[MAXN+5];
void solve()
{
	int M,N,a,b,i,x,s;
	vector <int> :: iterator it;
	in >> N >> M;
	FOR(i,1,M)
	{
		in >> a >> b;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	EKLE(1,0);
	while(!qx.empty())
	{
		BAK(x,s);
		res[x] = s;
		for(it = G[x].begin(); it!=G[x].end(); ++it)
			if(!visited[*it])
				EKLE(*it,s+1);
	}
	out << *max_element(res+1,res+N+1) << endl;
}
int main()
{
	solve();
	return 0;
}
