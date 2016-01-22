//SORU 542
//PROGRAM C++
#include <iostream>
#include <fstream>
#include <queue>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define INPUT "cowhome.in"
#define OUTPUT "cowhome.out"
#define MAXN 1000
#define EKLE(x,s) pq.push(make_pair(-(s),x))
#define BAK(x,s) { x = pq.top().second; s = -pq.top().first; pq.pop(); }
using namespace std;
ifstream in(INPUT);
ofstream out(OUTPUT);
priority_queue <pair <int,int> > pq;
int M,N;
int A[MAXN+5][MAXN+5],d[MAXN+5];
int dijkstra(int a)
{
	int i,x,s;
	FOR(i,1,N) d[i] = 100000000;
	d[a] = 0;
	EKLE(a,0);
	while(!pq.empty())
	{
		BAK(x,s);
		FOR(i,1,N)
			if(A[x][i] && s + A[x][i] < d[i])
			{
				d[i] = s + A[x][i];
				EKLE(i,(s+A[x][i]));
			}
	}
	return d[N];
}
void solve()
{
	int a,b,c,i;
	in >> M >> N;
	FOR(i,1,M)
	{
		in >> a >> b >> c;
		A[a][b] = A[b][a] = A[a][b] ? min(A[a][b],c) : c;
	}
	out << dijkstra(1) << endl;
}
int main()
{
	solve();
	return 0;
}
