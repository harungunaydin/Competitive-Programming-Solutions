#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#define f first
#define s second
#define FOR(i,a,b) for(i=a; i<=b; i++)
using namespace std;
int N,S;
int d[100005];
queue <int> Q;
vector < pair <int,int> > V[100005];
void solve()
{
	int c,i,maxi=0,top=0,x,y;
	scanf("%d %d",&N,&S);
	FOR(i,1,N-1)
	{
		scanf("%d %d %d",&x,&y,&c);
		V[x].push_back( make_pair(y,c) );
		V[y].push_back( make_pair(x,c) );
		top+=c;
	}
	Q.push(S);
	while(!Q.empty())
	{
		x=Q.front(); Q.pop();
		FOR(i,0,V[x].size()-1)
			if(!d[V[x][i].f])
			{
				d[V[x][i].f]=d[x]+V[x][i].s;
				Q.push(V[x][i].f);
				if(d[V[x][i].f]>maxi)
					maxi=d[V[x][i].f];
			}
	}
	printf("%d\n",2*top-maxi);

}
int main()
{
	solve();
	return 0;
}
