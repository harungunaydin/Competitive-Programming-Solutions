#include <iostream>
#include <map>
#include <queue>
#include <vector>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define mp(x,y) make_pair(x,y)
#define f first
#define s second
#define EKLE(x,s) Q.push(mp(-s,x))
#define BAK(x,s) { x=Q.top().second; s=-Q.top().first; Q.pop(); }
using namespace std;
typedef pair <int,int> pii;
priority_queue < pii > Q;
map <pii,int> mp;
map <pii,int> :: iterator it2;
map <pii,bool> kont;
vector < pii > V[50005];
vector < pii > :: iterator it;
int M,N;
int d[50005];
int shortest_path(int a)
{
	int i,s,x;
	FOR(i,1,N) d[i]=100000000;
	d[a]=0;
	EKLE(a,0);
	while(!Q.empty())
	{
		BAK(x,s);
		for(it=V[x].begin(); it!=V[x].end(); ++it)
		{
			if(s + it->s < d[ it->f ] )
			{
				d[ it->f ] = s + it->s;
				EKLE(it->f,d[it->f]);
			}
		}
	}
	return d[N];
}
void solve()
{
	int c,i,x,y;
	scanf("%d %d",&N,&M);
	FOR(i,1,M)
	{
		scanf("%d %d %d",&x,&y,&c);
		if(kont[mp(x,y)] && c < mp[mp(x,y)])
		{
			mp[mp(x,y)]=c;
			if(kont[mp(y,x)] && mp[mp(y,x)] < c) mp[mp(x,y)]=mp[mp(y,x)];
			continue;
		}
		if(!kont[mp(x,y)]) mp[mp(x,y)]=c;
		kont[mp(x,y)]=true;
	}
	for(it2=mp.begin(); it2!=mp.end(); ++it2)
	{
		V[it2->f.f].push_back(mp(it2->f.s,it2->s));
		V[it2->f.s].push_back(mp(it2->f.f,it2->s));
	}
	printf("%d\n",shortest_path(1));
}
int main()
{
	solve();
	return 0;
}
