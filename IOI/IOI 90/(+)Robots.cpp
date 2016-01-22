#include <iostream>
#include <set>
#include <queue>
#include <vector>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define EKLE(a,b,c,s) { q1.push(a); q2.push(b); q3.push(c); qs.push(s); durum[a][b][c] = true; }
#define BAK(a,b,c,s)  { a = q1.front(); b = q2.front(); c = q3.front(); s = qs.front(); q1.pop(); q2.pop(); q3.pop(); qs.pop(); }
#define EKLE2(x,s)    { qx.push(x); qs.push(s); }
#define BAK2(x,s)     { x = qx.front(); s = qs.front(); qx.pop(); qs.pop(); }
#define MAXN 50
using namespace std;
vector <int> G[MAXN+5];
set <int> st[MAXN+5][5];
queue <int> q1,q2,q3,qs;
int A[10],X[10];
int K,M,N;
bool durum[MAXN+5][MAXN+5][MAXN+5];
void read()
{
	int a,b,i;
	scanf("%d %d",&M,&N);
	FOR(i,1,N)
	{
		scanf("%d %d",&a,&b);
		G[a].push_back(b);
		G[b].push_back(a);
	}
	scanf("%d",&K);
	FOR(i,1,K)
		scanf("%d %d",X+i,A+i);
}
bool kontrol(int a,int b,int c)
{
	if(K == 3) return (a == b && b == c) ? 1 : 0;
	return a == b;
}
void BFS(int node)
{
	vector <int> :: iterator it;
	queue <int> qs,qx;
	int s,x;
	EKLE2(node,0);
	while(!qx.empty())
	{
		BAK2(x,s);
		if(s && x) st[node][s].insert(x);
		if(s == 2) continue;
		for(it = G[x].begin(); it!=G[x].end(); ++it)
				EKLE2(*it,s+1);
	}
}
void solve()
{
	set <int> :: iterator it,it2,it3;
	int i,j,s,t;
	EKLE(X[1],X[2],X[3],0);
	while(!q1.empty())
	{
		BAK(X[1],X[2],X[3],s);
		if(kontrol(X[1],X[2],X[3])) { printf("%d\n",s); return; }
		if(K == 2)
		{
			for(it = st[X[1]][A[1]].begin(); it!= st[X[1]][A[1]].end(); ++it)
				for(it2 = st[X[2]][A[2]].begin(); it2!=st[X[2]][A[2]].end(); ++it2)
					if(!durum[*it][*it2][0])
						EKLE(*it,*it2,0,s+1);
		}
		else
			for(it = st[X[1]][A[1]].begin(); it != st[X[1]][A[1]].end(); ++it)
				for(it2 = st[X[2]][A[2]].begin(); it2 != st[X[2]][A[2]].end(); ++it2)
					for(it3 = st[X[3]][A[3]].begin(); it3 != st[X[3]][A[3]].end(); ++it3)
						if(!durum[*it][*it2][*it3])
							EKLE(*it,*it2,*it3,s+1);
	}
	printf("IMPOSSIBLE\n");
}
int main()
{
	read();
	int i;
	FOR(i,1,N)
		BFS(i);
	solve();
	return 0;
}
