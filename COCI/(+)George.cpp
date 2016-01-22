#include <iostream>
#include <queue>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define f first
#define s second
#define EKLE(x,s) pq.push(make_pair(-(s),x))
#define BAK(x,s) { x = pq.top().s; s = - pq.top().f; pq.pop(); }
#define INF 100000000
#define MAXN 1000
using namespace std;
typedef pair <int,int> pii;
priority_queue <pii> pq;
int S,F,G,K,M,N;
int B[MAXN+5],C[MAXN+5],D[MAXN+5];
int A[MAXN+5][MAXN+5];
bool E[MAXN+5][MAXN+5];
void read()
{
	int a,b,c,i,s(0);
	scanf("%d %d",&N,&M);
	scanf("%d %d %d %d",&S,&F,&K,&G);
	FOR(i,1,G)
	{
		scanf("%d",B+i);
		D[B[i]] = i;
		if(i>1)
		E[B[i-1]][B[i]] = true;
	}
	FOR(i,1,M)
	{
		scanf("%d %d %d",&a,&b,&c);
		A[a][b] = A[b][a] = (A[a][b]) ? min(A[a][b],c) : c;
	}
	FOR(i,1,G-1)
		C[i+1] = s+=A[B[i]][B[i+1]];
}
bool control(int a,int b,int s)
{
	if(E[a][b])
		return !(C[D[a]] < s && s < C[D[b]]);
	if(E[b][a])
		return !(C[D[b]] < s && s < C[D[a]]);
	return 1;
}
int Dijkstra()
{
	int a,a2,b,b2,i,s,x;
	int d[MAXN+5];
	FOR(i,1,N) d[i] = INF;
	d[S] = 0;
	EKLE(S,K);
	while(!pq.empty())
	{
		BAK(x,s);
		FOR(i,1,N)
			if(A[x][i])
			{
				if(control(x,i,s))
				{
					if(s+A[x][i] <= d[i])
					{
						d[i] = s + A[x][i];
						EKLE(i,d[i]);
					}
				}
				else
				{
					if(E[x][i])
						EKLE(x,C[D[i]]);
					else
						EKLE(x,C[D[x]]);
				}
			}
	}
	return d[F] - K;
}
int main()
{
	int i;
	int K[10000];
	fill(K,K+5000,0);
	FOR(i,1,70 )
	{
		int a;
		cin >> a;
		if(K[a]) { cout << "asdf\n";cout << a << " " << i << " " << K[a] << endl; }
		K[a] = i;
	}
	//read();
	//printf("%d\n",Dijkstra());
	system("PAUSE");
	return 0;
}
