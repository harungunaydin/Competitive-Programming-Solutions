#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define EKLE(x,s) Q.push(make_pair(-s,x))
#define BAK(x,s) { x=Q.top().second; s=-Q.top().first; Q.pop(); }
#define INFINITY 1000000000
using namespace std;
priority_queue < pair <int,int> > Q;
vector <int> V[5005],V2[5005];
vector <int> :: iterator it;
int d[1005];
int M,N;
int B[400000][4],C[400000];
int A[1005][1005];
int ShortestPath(int a,int b)
{
	int i,t,s,x;
	FOR(i,1,N) d[i]=INFINITY;
	d[a]=0;
	V2[a].push_back(a);
	EKLE(a,0);
	while(!Q.empty())
	{
		BAK(x,s);
		for(it=V[x].begin(); it!=V[x].end(); ++it)
		{
			t=s+A[x][*it];
			if(A[x][*it] && t<d[*it])
			{
				V2[*it]=V2[x];
				V2[*it].push_back(*it);
				d[*it]=t;
				EKLE(*it,t);
			}
		}
	}
	return d[b];
}
void read()
{
	int c,i,x,y;
	scanf("%d %d",&N,&M);
	FOR(i,1,M)
	{
		scanf("%d %d %d",&x,&y,&c);
		B[i][1]=x;
		B[i][2]=y;
		B[i][3]=c;
		A[x][y]=A[y][x]=c;
		V[x].push_back(y);
		V[y].push_back(x);
	}
}
void solve()
{
	int a,c,i,k1,k2,maxi=0;
	ShortestPath(N,1);
	a=V2[1].size();
	FOR(i,0,a-1) C[i+1]=V2[1][i];
	FOR(i,1,a)
	{
		c=A[C[i]][C[i+1]];
		A[C[i]][C[i+1]]=0;
		maxi=max(maxi,ShortestPath(N,1));
		A[C[i]][C[i+1]]=c;
	}
	printf("%d\n",maxi);
}
int main()
{
	read();
	solve();
	return 0;
}
