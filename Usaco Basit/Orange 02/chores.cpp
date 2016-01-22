//SORU 334
//PROGRAM C++
#include <iostream>
#include <fstream>
#include <queue>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define all(x) x.begin(),x.end()
#define INPUT "chores.in"
#define OUTPUT "chores.out"
#define MAXN 10000
#define EKLE(x,s) pq.push(make_pair(-(s),x))
#define BAK(x,s) { x = pq.top().second; s = - pq.top().first; pq.pop(); }
using namespace std;
ifstream in(INPUT);
ofstream out(OUTPUT);
priority_queue < pair <int,int> > pq;
vector <int> G[MAXN+5];
int N;
int B[MAXN+5],In[MAXN+5];
void solve()
{
	int a,b,i,j,res=0,x,s;
	in >> N;
	FOR(i,1,N)
	{
		in >> B[i] >> In[i];
		if(!In[i]) EKLE(i,B[i]);
		FOR(j,1,In[i])
		{
			in >> a;
			G[a].push_back(i);
		}
	}
	vector <int> :: iterator it;
	while(!pq.empty())
	{
		BAK(x,s);
		res = max(res,s);
		for(it = G[x].begin(); it!=G[x].end(); ++it)
			if(!(--In[*it]))
				EKLE(*it,s+B[*it]);
	}
	out << res << endl;
}
int main()
{
	solve();
	return 0;
}
