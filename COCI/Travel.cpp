#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define EKLE(x,y,s) pq.push(make_pair(-(s),make_pair(y,x)))
#define BAK(x,y,s) { x = pq.top().second.second; y = pq.top().second.first; s = - pq.top().first; pq.pop(); }
#define MAXK 2000
#define MAXN 1000
using namespace std;
typedef pair < int , pair < short , short > > piss;
priority_queue < piss > pq;
vector < short > V[MAXN+5];
class station
{
	public:
		short c,s;
		short A[MAXN+5],D[MAXN+5],M[MAXN+5],S[MAXN+5];
		station() { for(int i = 0; i < MAXN+4 ; i++) A[i] = M[i] = S[i] = D[i] = 0; }
		void read(int t)
		{
			int i;
			scanf("%hd %hd",&s,&c);
			FOR(i,1,s) { scanf("%hd",A+i); V[A[i]].push_back(t); D[A[i]] = i; }
			FOR(i,1,s-1) { scanf("%hd",S+i); M[A[i+1]] = M[A[i]] + S[i]; }
		}
}B[MAXK+5];
int K,N,T,X,Y,Gx,Mx;
int d[MAXN+5];
void solve()
{
	vector < short > :: iterator it;
	int dakika,a,i,k,m,q,x,y,s,saat,t;
	scanf("%d %d %d %d %d %d",&N,&K,&X,&Y,&Gx,&Mx);
	FOR(i,1,K) B[i].read(i);
	FOR(i,1,N) d[i] = 20000;
	T = Gx * 60 + Mx;
	for(it = V[X].begin(); it != V[X].end(); ++it)
	{
		d[X] = 0;
		EKLE(X,*it,0);
	}
	while(!pq.empty())
	{
		BAK(x,y,s);
		cout << x << " " << s << endl;
		t = (s + T) % 1440;
		if(x == Y) { printf("%d %d\n",t/60,t%60); return; }
		for(it = V[x].begin(); it != V[x].end(); ++it)
		{
			i = *it;
			a = (s/B[i].c) + 1;
			a = (a + 1) * B[i].c - B[i].M[x];
			k = B[i].S[B[i].D[x]];
			m = B[i].A[B[i].D[x]+1];
			if(i == y) a = 0;
			if(s+a+k < d[m])
			{
				d[m] = s + a + k;
				EKLE(m,i,d[m]);
			}
			q = B[i].M[ B[i].A[B[i].s] ] - B[i].M[x];
			k = B[i].S[B[i].D[x]-1];
			m = B[i].A[B[i].D[x]-1];
			if(i == y) a = 0;
			if(s + a + k < d[m])
			{
				d[m] = s + a + k;
				EKLE(m,i,d[m]);
			}
		}
	}
}
int main()
{
	solve();
	return 0;
}
