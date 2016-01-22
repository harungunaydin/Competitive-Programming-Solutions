#include <iostream>
#include <algorithm>
#include <cstdio>
#include <queue>
#include <vector>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define f first
#define s second
#define MAXN 80001
using namespace std;
typedef pair < int , int > pii;
class cubuk
{
	public:
		int a,x,h;
		bool k;
		void set(int i,int b,int c,bool d) { a = i; x = b; h = c; k = d; }
}A[MAXN];
inline bool cmp( const cubuk &a , const cubuk &b ) { return a.x < b.x; }
priority_queue < pii > pq;
int N;
bool H[MAXN];
void solve()
{
	long long res(0);
	int a,b,cur(1),i,h,t;
	scanf("%d",&N);
	FOR(i,1,N)
	{
		scanf("%d %d %d",&a,&b,&h);
		A[i].set(i,a,h,0);
		A[i+N].set(i,b,h,1);
	}
	N <<= 1;
	pq.push(make_pair(0,0));
	sort(A+1,A+N+1,cmp);
	FOR(i,1,N)
	{
		while(!pq.empty() && H[pq.top().s]) pq.pop();
		res += ( pq.top().f * (long long) (A[i].x - A[i-1].x) );
		if(A[i].k) H[A[i].a] = true;
		else pq.push(make_pair(A[i].h,A[i].a));
	}
	printf("%lld\n" , res );
}
int main()
{
	solve();
	return 0;
}
