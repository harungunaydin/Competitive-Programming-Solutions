#include <iostream>
#include <cmath>
#include <cstdio>
#include <queue>
#include <vector>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define EKLE(x,s) { qx.push(x); qs.push(s); visited[x] = vis; }
#define BAK(x,s)  { x = qx.front(); s = qs.front(); qx.pop(); qs.pop(); }
#define MAXN 40005
using namespace std;
typedef pair < int , int > pii;
inline int Abs( int a ) { return a > 0 ? a : -a; }
inline int Max( int a , int b ) { return a > b ? a : b; }
inline int Min( int a , int b ) { return a < b ? a : b; }
class circle
{
	public:
		int a,r,x,y;
		circle() { a = r = x = y = 0; }
		void read() { scanf("%d %d %d %d",&x,&y,&r,&a); }
}A[MAXN];
queue < int > qx,qs;
vector < int > G[MAXN];
int K,N,vis;
int visited[MAXN];
int d[MAXN];
double Distance(int a,int b) { return sqrt( (A[a].x - A[b].x) * (A[a].x - A[b].x) + (A[a].y - A[b].y) * (A[a].y - A[b].y) ); }
void BFS(int a)
{
	vis++;
	vector < int > :: iterator it;
	int s,x;
	EKLE(a,0);
	while(!qx.empty())
	{
		BAK(x,s);
		d[x] = s;
		for(it = G[x].begin(); it != G[x].end(); ++it)
			if(visited[*it] != vis)
				EKLE(*it,s+1);
	}
}
void solve()
{
	int i,j,k,mini,res(0);
	scanf("%d %d",&N,&K);
	FOR(i,1,N)
		A[i].read();
	FOR(i,1,N)
	{
		mini = 5000;
		k = 0;
		FOR(j,1,N)
		{
			if(i != j && A[i].r + Distance(i,j) < A[j].r && A[j].r < mini)
			{
				mini = A[j].r;
				k = j;
			}
		}
		if(k)
		{
			G[i].push_back(k);
			G[k].push_back(i);
		}
		else
		{
			G[0].push_back(i);
			G[i].push_back(0);
		}
	}
	FOR(i,1,N)
	{
		BFS(i);
		FOR(j,i+1,N)
			if(d[j] <= K)
				res = Max( res , Abs( A[i].a - A[j].a ) );
	}
	printf("%d\n" , res );
}
int main()
{
	solve();
	return 0;
}
