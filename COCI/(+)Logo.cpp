#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define EKLE(x) { Q.push(x); visited[x] = true; }
#define BAK(x)  { x = Q.front(); Q.pop(); }
#define MAXN 1000
using namespace std;
queue <int> Q;
vector <int> V[MAXN+5];
int N,res(0);
bool visited[MAXN+5];
class rect
{
	public:
		int x1,x2,y1,y2;
		rect() { x1 = x2 = y1 = y2 = 0; }
		void read() { scanf("%d %d %d %d",&x1,&y1,&x2,&y2); }
}D[MAXN+5];
void BFS(int a)
{
	res++;
	vector <int> :: iterator it;
	int x;
	EKLE(a);
	while(!Q.empty())
	{
		BAK(x);
		for(it = V[x].begin(); it!=V[x].end(); ++it)
			if(!visited[*it])
				EKLE(*it);
	}
}
bool icinde_mi(rect a,rect b)
{
	return b.x1 < a.x1 && a.x2 < b.x2 && b.y1 < a.y1 && a.y2 < b.y2;
}
bool control(rect a,rect b)
{
	return (a.x2 < b.x1 || b.x2 < a.x1 || a.y1 > b.y2 || b.y1 > a.y2) || icinde_mi(a,b) || icinde_mi(b,a);
}
void solve()
{
	int i,j;
	scanf("%d",&N);
	FOR(i,1,N)
	{
		D[i].read();
		FOR(j,1,i-1)
			if(!control(D[i],D[j]))
			{
				V[i].push_back(j);
				V[j].push_back(i);
			}
		if(!res)
			if(((!D[i].x1 || !D[i].x2) && (D[i].y1 <= 0 && D[i].y2 >= 0)) || ((!D[i].y1 || !D[i].y2) && ( D[i].x1 <= 0 && D[i].x2 >= 0 )))
				res--;
	}
	FOR(i,1,N)
		if(!visited[i])
				BFS(i);
	printf("%d\n",res);
}
int main()
{
	solve();
	return 0;
}
