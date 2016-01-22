#include <iostream>
#include <cstdio>
#include <cstring>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define MAXN 1005
using namespace std;
typedef pair < int , int > pii;
int vis,x1,x2,y1,y2;
int F[MAXN][MAXN],H[MAXN][MAXN];
void update(int x1,int y1)
{
	if(H[x1][y1] == vis) return;
	H[x1][y1] = vis;
	int x,y;
	for(x = x1; x <= 1001; x += x&-x)
		for(y = y1; y <= 1001; y += y&-y)
			F[x][y]++;
}
int find(int x1,int y1)
{
	int s(0),x,y;
	for(x = x1; x > 0; x -= x&-x)
		for(y = y1; y > 0; y -= y&-y)
			s += F[x][y];
	return s;
}
void solve()
{
	int Q,i,k;
	scanf("%d",&Q);
	FOR(i,1,Q)
	{
		scanf("%d",&k);
		if(k)
		{
			scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
			x1++; y1++; x2++; y2++;
			printf("%d\n" , find(x2,y2) - find(x2,y1-1) - find(x1-1,y2) + find(x1-1,y1-1) );
		}
		else
		{
			scanf("%d %d",&x1,&y1);
			x1++; y1++;
			update(x1,y1);
		}
	}
}
int main()
{
	int T,i;
	scanf("%d",&T);
	while(T--)
	{
		memset( F , 0 , sizeof F );
		printf("Case %d:\n",++vis);
		solve();
	}
	return 0;
}
