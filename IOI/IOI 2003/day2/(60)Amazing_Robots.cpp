//SORU 811
//PROGRAM C++
#include <cstdio>
#include <cstring>
#include <queue>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define INPUT "robots.in"
#define OUTPUT "robots.out"
#define f first
#define s second
#define EKLE(x1,y1,x2,y2,s) { qx1.push(x1); qy1.push(y1); qx2.push(x2); qy2.push(y2); qs.push(s); }
#define BAK(x1,y1,x2,y2,s)  { x1 = qx1.front(); y1 = qy1.front(); x2 = qx2.front(); y2 = qy2.front(); s = qs.front();  SIL; }
#define SIL { qx1.pop(); qy1.pop(); qx2.pop(); qy2.pop(); qs.pop(); }
#define OUT(r,x,y) ( !x || !y || x == r.M + 1 || y == r.N + 1 )
#define MAXN 22
#define MAXT 85
using namespace std;
typedef pair < int , int > pii;
class bekci
{
	public:
		int k,x,y;
		char c;
		bekci() {  }
		void read() { scanf("%d %d %d %c",&x,&y,&k,&c); }
};
class robot
{
	public:
		bekci B[20];
		char A[MAXN][MAXN];
		int G,M,N,k,rx,ry;
		char c;
		robot() { memset( A , 0 , sizeof A ); }
		void read()
		{
			int i,j;
			scanf("%d %d",&M,&N);
			FOR(i,1,M)
				FOR(j,1,N)
				{
					scanf(" %c",A[i]+j);
					if(A[i][j] == 'X') rx = i,ry = j;
				}
			scanf("%d",&G);
			FOR(i,1,G)
				B[i].read();
		}
}R1,R2;
queue < int > qs,qx1,qx2,qy1,qy2;
int yon2[150];
int hash[MAXN][MAXN][MAXN][MAXN] , yon[4][2] = { {1,0},{0,1},{-1,0},{0,-1} };
int x2,y2;
pii hesapla(bekci b,int s)
{
	int t = s % ( 2 * b.k - 2 );
	int k = yon2[ b.c ];

	if(t < b.k) return make_pair( b.x + t * yon[k][0] , b.y + t * yon[k][1] );
	
	t = t - b.k + 1;

	return make_pair( b.x + (b.k-t-1) * yon[k][0] , b.y + (b.k-t-1) * yon[k][1] );

}
bool kontrol(robot R,int x,int y,int xx,int yy,int s)
{
	pii p1,p2;
	int i;
	FOR(i,1,R.G)
	{
		p1 = hesapla(R.B[i],s-1);
		p2 = hesapla(R.B[i],s);

		if(p1.f == xx && p1.s == yy && p2.f == x && p2.s == y) return false;
		if(xx == p2.f && yy == p2.s) return false;
	}
	return true;
}
bool kontrol2(robot R,int x,int y,int s)
{
	int i;
	FOR(i,1,R.G)
	{
		pii p = hesapla(R.B[i],s);
		if(p.f == x && p.s == y) return false;
	}
	return true;
}
int solve()
{

	yon2['E'] = 1; yon2['N'] = 2; yon2['W'] = 3;

	R1.read();
	R2.read();

	int i,o1,o2,s,x1,x2,y1,y2,xx1,xx2,yy1,yy2;

	EKLE(R1.rx,R1.ry,R2.rx,R2.ry,0);

	while(!qx1.empty())
	{
		BAK(x1,y1,x2,y2,s);

		o1 = OUT(R1,x1,y1);
		o2 = OUT(R2,x2,y2);
		if(o1 && o2) return s;
		FOR2(i,4)
		{
			if(!o1 && !o2)
			{
				xx1 = x1 + yon[i][0]; yy1 = y1 + yon[i][1];
				xx2 = x2 + yon[i][0]; yy2 = y2 + yon[i][1];

				bool f1 = R1.A[xx1][yy1] != '#';
				bool f2 = R2.A[xx2][yy2] != '#';

				if(f1 && f2)
				{
					if(kontrol(R1,x1,y1,xx1,yy1,s+1) && kontrol(R2,x2,y2,xx2,yy2,s+1) && hash[xx1][yy1][xx2][yy2] < MAXT)
					{
						hash[xx1][yy1][xx2][yy2]++;
						EKLE(xx1,yy1,xx2,yy2,s+1);
					}
				}
				else if(f1 && !f2)
				{
					if(kontrol(R1,x1,y1,xx1,yy1,s+1) && kontrol2(R2,x2,y2,s+1) && hash[xx1][yy1][x2][y2] < MAXT)
					{
						hash[xx1][yy1][x2][y2]++;
						EKLE(xx1,yy1,x2,y2,s+1);
					}
				}
				else if(!f1 && f2)
				{
					if(kontrol(R2,x2,y2,xx2,yy2,s+1) && kontrol2(R1,x1,y1,s+1) && hash[x1][y1][xx2][yy2] < MAXT)
					{
						hash[x1][y1][xx2][yy2]++;
						EKLE(x1,y1,xx2,yy2,s+1);
					}
				}
				else
				{
					if(kontrol2(R1,x1,y1,s+1) && kontrol2(R2,x2,y2,s+1) && hash[x1][y1][x2][y2] < MAXT)
					{
						hash[x1][y1][x2][y2]++;
						EKLE(x1,y1,x2,y2,s+1);
					}
				}
			}
			else if(!o1 && o2)
			{
				xx1 = x1 + yon[i][0]; yy1 = y1 + yon[i][1];

				if(R1.A[xx1][yy1] != '#' && kontrol(R1,x1,y1,xx1,yy1,s+1) && hash[xx1][yy1][x2][y2] < MAXT)
				{
					hash[xx1][yy1][x2][y2]++;
					EKLE(xx1,yy1,x2,y2,s+1);
				}
			}
			else if(!o2 && o1)
			{
				xx2 = x2 + yon[i][0]; yy2 = y2 + yon[i][1];

				if(R2.A[xx2][yy2] != '#' && kontrol(R2,x2,y2,xx2,yy2,s+1) && hash[x1][y1][xx2][yy2] < MAXT)
				{
					hash[x1][y1][xx2][yy2]++;
					EKLE(x1,y1,xx2,yy2,s+1);
				}
			}
		}
	}

	return -1;

}
int main()
{
	freopen(INPUT,"r",stdin);
	freopen(OUTPUT,"w",stdout);
	printf("%d\n" , solve() );
	return 0;
}
