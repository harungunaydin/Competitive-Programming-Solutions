//SORU 504
//PROGRAM C++
#include <iostream>
#include <fstream>
#include <algorithm>
#include <queue>
#include <climits>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define INPUT "bparty.in"
#define OUTPUT "bparty.out"
#define MAXN 1000
#define f first
#define s second
#define EKLE(x,s) pq.push(make_pair(-(s),x))
#define BAK(x,s) { x = pq.top().s; s = -pq.top().f; pq.pop(); }
using namespace std;
ifstream in(INPUT);
ofstream out(OUTPUT);
priority_queue < pair <int,int> > pq;
int M,N,X;
int A[MAXN+5][MAXN+5],d[MAXN+5];
void dijkstra(int a)
{
	int i,s,x;
	EKLE(a,0);
	FOR(i,1,N)	d[i] = INT_MAX/2;
	d[a] = 0;
	while(!pq.empty())
	{
		BAK(x,s);
		FOR(i,1,N)
			if(A[x][i] && s + A[x][i] < d[i])
			{
				d[i] = s + A[x][i];
				EKLE(i,s+A[x][i]);
			}
	}
}
void read()
{
	int a,b,c,i;
	in >> N >> M >> X;
	FOR(i,1,M)
	{
		in >> a >> b >> c;
		A[a][b] = A[b][a] = (A[a][b])? min(c,A[a][b]) : c;
	}
}
void solve()
{
	dijkstra(X);
	int i,maxi=0;
	FOR(i,1,N)
		maxi=max(maxi,d[i]);
	out << maxi*2 << endl;
}
int main()
{
	read();
	solve();
	return 0;
}
