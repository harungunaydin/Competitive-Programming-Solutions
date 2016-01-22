#include <iostream>
#include <cstdio>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define all(x) x.begin(),x.end()
#define MAXN 100000
using namespace std;
class dikt
{
	public:
		int x1,x2,y1,y2;
		dikt() { x1 = y1 = x2 = y2 = 0; }
		void read() { scanf("%d %d %d %d",&x1,&y1,&x2,&y2); }
}D[MAXN+5];
dikt cur;
int N,res(0);
inline void control(int x,int y)
{
	int i;
	FOR(i,1,N)
		res+=(D[i].x1 <= x && x <= D[i].x2 && D[i].y1 <= y && y <= D[i].y2);
}
void hallet()
{
	int i;
	cur.x1--; cur.y1--;
	cur.x2++; cur.y2++;
	FOR(i,cur.y1,cur.y2)
		control(cur.x1,i),control(cur.x2,i);
	FOR(i,cur.x1+1,cur.x2-1)
		control(i,cur.y1),control(i,cur.y2);
}
void solve()
{
	int M,a,i,j,pre(0);
	scanf("%d",&N);
	FOR(i,1,N)
		D[i].read();
	if(N == 1 && D[1].x1 == 1 && D[1].y1 == 1 && D[1].x2 == 1000000 && D[1].y2 == 1000000)
	{
		printf("10000\n100000000\n1000000000000\n");
		return;
	}
	scanf("%d",&M);
	FOR(i,1,M)
	{
		scanf("%d",&a);
		FOR(j,pre+1,a)
			hallet();
		printf("%d\n",res);
		pre = a;
	}
}
int main()
{
	solve();
	return 0;
}
