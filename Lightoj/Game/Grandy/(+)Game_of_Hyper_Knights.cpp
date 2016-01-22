#include <cstdio>
#include <cstring>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define KONTROL(x,y) ( x >= 0 && x <= 500 && y >= 0 && y <= 500 )
#define MAXN 501
using namespace std;
int A[MAXN][MAXN] , yon[6][2] = { {1,-2},{-1,-3},{-1,-2},{-2,-1},{-3,-1},{-2,1} };
int f(int x,int y)
{
	int &ret = A[x][y];
	if(ret != -1) return ret;

	bool K[7] = { false };
	int i,xx,yy;

	FOR2(i,6)
	{
		xx = x + yon[i][0];
		yy = y + yon[i][1];
		if(KONTROL(xx,yy))
			K[f(xx,yy)] = true;
	}
	FOR2(i,7)
		if(!K[i])
			return ret = i;

}
void solve()
{
	int N,i,t(0),x,y;
	scanf("%d",&N);
	FOR(i,1,N)
	{
		scanf("%d %d",&x,&y);
		t ^= f(x,y);
	}

	t ? printf("Alice\n") : printf("Bob\n");
}
int main()
{
	memset( A , -1 , sizeof A );
	int i,j;
	int T;
	scanf("%d",&T);
	FOR(i,1,T)
	{
		printf("Case %d: ",i);
		solve();
	}
	return 0;
}
