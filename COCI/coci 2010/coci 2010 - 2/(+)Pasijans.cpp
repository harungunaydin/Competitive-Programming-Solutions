#include <iostream>
#include <algorithm>
#include <cstdio>
#include <queue>
#include <vector>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define f first
#define s second
#define EKLE(x,s) pq.push(make_pair(-(s),x))
#define BAK(x,s) { x = pq.top().second; s = - pq.top().first; pq.pop(); }
#define mp(x,y) make_pair(x,y)
#define INF 2000000000
#define MAXN 2000000
using namespace std;
typedef pair < int , int > pii;
typedef pair < pii , int > piii;
priority_queue < pii > pq;
vector < int > V;
piii P[MAXN+5];
pii P2[MAXN+5];
int M,N;
int A[MAXN+5],B[MAXN+5],C[MAXN+5],D[MAXN+5];
bool hash[MAXN+5];
void read()
{
	int a,i,j,s;
	scanf("%d",&M);
	FOR(i,1,M)
	{
		scanf("%d",&s);
		B[i] = B[i-1] + s;
		FOR(j,B[i-1]+1,B[i]) D[j] = B[i];
		hash[B[i]] = true;
		FOR2(j,s)
		{
			scanf("%d",&A[++N]);
			C[N] = A[N];
		}
	}
}
void suffix_array()
{
	int i,j,k(1),s(0);
	FOR(i,1,N) P2[i] = mp( A[i] , i );
	sort(P2+1,P2+N+1);
	FOR(i,1,N)
	{
		j = i;
		s++;
		while(P2[i].f == P2[j].f && i <= N) A[P2[i++].s] = s;
		i--;
	}
	s = 0;
	while(k < N)
	{
		s = 0;
		FOR(i,1,N) P[i] = mp( mp( A[i] , (i+k > D[i]) ? INF : A[i+k]) , i );
		sort(P+1,P+N+1);
		FOR(i,1,N)
		{
			j = i;
			s++;
			while(P[i].f.f == P[j].f.f && P[i].f.s == P[j].f.s && i <= N) A[P[i++].s] = s;
			i--;
		}
		k <<= 1;
	}
}
void solve()
{
	int i,x,s;
	FOR2(i,M)
		EKLE(B[i]+1,A[B[i]+1]);
	while(!pq.empty())
	{
		BAK(x,s);
		V.push_back(C[x]);
		if(!hash[x])
			EKLE(x+1,A[x+1]);
	}
	FOR2(i,V.size())
		printf("%d%c",V[i],(i != V.size() - 1) ? ' ' : '\n');
}
int main()
{
	read();
	suffix_array();
	solve();
	return 0;
}
