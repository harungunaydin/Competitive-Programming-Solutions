#include <iostream>
#include <queue>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define all(x) x.begin(),x.end()
#define MAXN 
using namespace std;
priority_queue <int> pq[10];
void solve()
{
	int M,N,a,b,i,res(0);
	scanf("%d %d",&M,&N);
	FOR(i,1,M)
	{
		scanf("%d %d",&a,&b);
		if(pq[a].empty()) { res++; pq[a].push(b); }
		else
		{
			while(!pq[a].empty() && pq[a].top() > b) { res++; pq[a].pop(); }
			if(pq[a].top() != b) { res++; pq[a].push(b); }
		}
	}
	printf("%d\n",res);
}
int main()
{
	solve();
	return 0;
}
