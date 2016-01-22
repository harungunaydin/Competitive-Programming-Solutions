#include <iostream>
#include <vector>
#include <queue>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define EKLE(x,s) Q.push(make_pair(-(s),x))
#define BAK(x,s) { x=Q.top().s; s=-Q.top().f; Q.pop(); }
#define INFINITY (INT_MAX/2)
#define mp(x,y) make_pair(x,y)
#define f first
#define s second
using namespace std;
typedef pair <int,int> pii;
priority_queue < pii > Q;
vector < pii > V[25005];
vector < pii > :: iterator it;
int P,R,S,T;
int d[25005];
void shortest_path(int a)
{
	int i,x,s;
	FOR(i,1,T) d[i]=INFINITY;
	d[a]=0;
	EKLE(a,0);
	while(!Q.empty())
	{
		BAK(x,s)
		for(it=V[x].begin(); it!=V[x].end(); ++it)
			if(s + it->s < d[it->f])
			{
				d[it->f]=s + it->s;
				EKLE(it->f,s + it->s);
			}
	}
}
void solve()
{
	int i,x,y,c;
	scanf("%d %d %d %d",&T,&R,&P,&S);
	FOR(i,1,R)
	{
		scanf("%d %d %d",&x,&y,&c);
		V[x].push_back(mp(y,c));
		V[y].push_back(mp(x,c));
	}
	FOR(i,1,P)
	{
		scanf("%d %d %d",&x,&y,&c);
		V[x].push_back(mp(y,c));
	}
	shortest_path(S);
	FOR(i,1,T)
		(d[i] == INFINITY)? printf("NO PATH\n") : printf("%d\n",d[i]);
}
int main()
{
	solve();
	getchar();
	getchar();
	system("PAUSE");
	return 0;
}
