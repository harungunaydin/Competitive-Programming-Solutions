#include <iostream>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define f first
#define s second
#define MAXN 200
#define MAXM 10000
#define KONTROL(x,y) (x < 1 || x > N | y < 1 || y > N)
using namespace std;
typedef pair <int,int> pii;
string W[MAXN+5][MAXN+5];
int K,M,N,k,x,y;
int yon[4][2] = { {1,0},{0,1},{-1,0},{0,-1} };
pii A[MAXN+5][MAXN+5][7][4];
long long solve()
{
	long long gun;
	int a,b,i,s(1);
	char c;
	bool flag;
	scanf("%d %d",&N,&K);
	scanf("%d",&M);
	FOR(i,1,M)
	{
		scanf("%d %d",&a,&b);
		cin >> W[a][b];
	}
	flag = true;
	K++;
	gun = 0;
	x = y = k = 1;
	while(1)
	{
		if(s == K) return gun;
		if(A[x][y][gun%7][k].s && flag)
		{
			flag = false;
			int fark = s - A[x][y][gun%7][k].s,t;
			t = (K-s)/fark;
			s+=t*fark;
			gun+=t*(gun-A[x][y][gun%7][k].f);
			continue;
		}
		A[x][y][gun%7][k] = make_pair(gun,s);
		if(!W[x][y].empty())
		{
			c = W[x][y][gun%7];
			if(c == 'L') { k = (k+1)%4; if(++s == K) return gun; }
			if(c == 'R') { k = (!k) ? 3 : k-1; if(++s == K) return gun; }
		}
		if(KONTROL(x+yon[k][0],y+yon[k][1])) { k = (k+2)%4; if(++s == K) return gun; }
		x+=yon[k][0];
		y+=yon[k][1];
		gun++;
	}
}
int main()
{
	printf("%lld\n",solve());
	return 0;
}
