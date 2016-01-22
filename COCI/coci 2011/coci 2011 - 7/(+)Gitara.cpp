#include <algorithm>
#include <cstdio>
#include <queue>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define TFOR(i,a,b) for(i=a; i>=b; i--)
#define all(x) x.begin(),x.end()
#define MAXN 300005
using namespace std;
int read()
{
	int res(0),sign(1);
	char c;
	while(1)
	{
		c = getchar();
		if('0' <= c && c <= '9') { res = c - '0'; break; }
		else if(c == '-') { sign = -1; break; }
	}
	while(1)
	{
		c = getchar();
		if('0' <= c && c <= '9') res = res*10 + c - '0';
		else break;
	}
	return res * sign;
}
priority_queue < int > pq[MAXN];
int M,N;
void solve()
{
	M = read(); N = read();
	int a,b,i,res(0);
	FOR(i,1,M)
	{
		scanf("%d %d",&a,&b);

		while(!pq[a].empty())
		{
			if(pq[a].top() == b)
				break;
			if(pq[a].top() < b)
			{
				pq[a].push(b);
				res++;
				break;
			}
			pq[a].pop();
			res++;
		}
		if(pq[a].empty())
		{
			pq[a].push(b);
			res++;
		}
	}

	printf("%d\n" , res );

}
int main()
{
	solve();
	return 0;
}
