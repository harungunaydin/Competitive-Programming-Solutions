#include <iostream>
#include <queue>
#include <vector>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define all(x) x.begin(),x.end()
#define MAXN 100
#define mp make_pair
#define EKLE(x,s) pq.push(make_pair(-(s),x));
#define BAK(x,s) { x = pq.top().second; s = -pq.top().first; pq.pop(); }
#define INFINITY 100000000
#define f first
#define s second
using namespace std;
typedef pair <int,int> pii;
typedef pair <int,pii> piii;
priority_queue <pii> pq;
vector <piii> V[MAXN+5];
int A,B,M,N;
void read()
{
	int a,b,c,d,i;
	scanf("%d %d %d %d",&N,&A,&B,&M);
	FOR(i,1,M)
	{
		scanf("%d %d %d %d",&a,&b,&c,&d);
		V[a].push_back(mp(c,mp(b,d)));
	}
}
int solve()
{
	int i,s,x;
	vector <piii> :: iterator it;
	EKLE(A,0);
	while(!pq.empty())
	{
		BAK(x,s);
		if(x == B) break;
		for(it = V[x].begin(); it!=V[x].end(); ++it)
			if(s <= it->s.f)
				EKLE(it->f,it->s.s);
	}
	return (pq.empty()) ? -1 : s;
}
int main()
{
	read();
	cout << solve() << endl;
	return 0;
}
