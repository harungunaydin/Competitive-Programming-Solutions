#include <iostream>
#include <cmath>
#include <cstdio>
#include <map>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define f first
#define s second
#define mp3(x,y,z) make_pair(make_pair(x,y),z)
#define EPS 0.00000001
#define ESIT(x,y) (abs(x-y) < EPS)
#define MAXN 5000
#define MAXL 400000
using namespace std;
typedef pair < int , int > pii;
class point
{
	public :
		 double x,y;
		 point() { x = y = 0; }
		 point(double a , double b) { x = a; y = b; }
		 void read() { scanf("%lf %lf",&x,&y); }
		 void print() { printf("( %.lf,%.lf )\n",x,y); }
		 bool operator == (point b)
		 {
			 return ESIT( x , b.x ) && ESIT( y , b.y );
		 }
}P[MAXN+5];
point make_point(double a , double b)
{
	point p(a,b);
	return p;
}
map < pair < pii , int > , bool > kont;
const point INF = make_point(-2000000.0,-2000000.0);
int N,maxi,k=20000000;
int K[MAXN+5],T2[MAXL+5];
int yon[10][2] = { {0,0},{-1,1},{0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1},{-1,0} };
class line
{
	public:
		double a,b,c;
		line() { a = b = c = 0; }
		line(double x,double y,double z) { a = x; b = y; c = z; }
}L[MAXN+5];
class bisi
{
	public:
		map < pii , short > mp;
}T[MAXL+5];
line make_line(double x,double y,double z)
{
	line l(x,y,z);
	return l;
}
line make_line_from_two_points(point a , point b)
{
	if(ESIT(b.x,a.x)) return make_line(1,0,-a.x);
	double m = (b.y-a.y)/(b.x-a.x),n;
	n = a.y - m*a.x;
	return make_line(m,-1,n);
}
point line_intersection(line l1 , line l2)
{
	double det = (l1.a*l2.b - l1.b*l2.a);
	if(ESIT( det , 0 )) return INF;
	double x = -(l1.c*l2.b - l2.c*l1.b)/det;
	double y = -(l1.a*l2.c - l2.a*l1.c)/det;
	return make_point(x,y);
}
double Distance(point a , point b)
{
	return sqrt( (b.x-a.x)*(b.x-a.x) + (b.y-a.y)*(b.y-a.y) );
}
bool hallet(int a,int b)
{
	if(ESIT(L[a].a,L[b].a) && ESIT(L[a].b,L[b].b) && ESIT(L[a].c,L[b].c))
	{
		point p1,p2;
		p1 = make_point(P[a].x + yon[K[a]][0] , P[a].y + yon[K[a]][1]);
		p2 = make_point(P[b].x + yon[K[b]][0] , P[b].y + yon[K[b]][1]);
		if(p2 == P[a] && p1 == P[b]) return 1;
		if(Distance(p1,p2) < Distance(P[a],P[b]))
		{
			int t = (int) (ESIT( P[a].x , P[b].x )) ? abs(P[a].y - P[b].y) : abs(P[a].x - P[b].x);
			if(!(t&1))
			{
				int x = (P[a].x+P[b].x)/2;
				int y = (P[a].y+P[b].y)/2;
				t/=2;
				if(!kont[mp3(x,y,t)])
				{
					kont[mp3(x,y,t)] = true;
					int m = ++T[t].mp[make_pair(x,y)];
					if(m == maxi) k = min(k,t);
					if(m > maxi)
					{
						maxi = m;
						k = t;
					}
				}
				return 1;
			}
		}
	}
	return 0;
}
void solve()
{
	point p;
	double t1,t2;
	int i,j;
	bool flag;
	scanf("%d",&N);
	FOR(i,1,N)
	{
		P[i].read(); scanf("%d",K+i);
		L[i] = make_line_from_two_points(P[i],make_point(P[i].x+yon[K[i]][0] , P[i].y+yon[K[i]][1]));
		kont.clear();
		FOR(j,1,i-1)
		{
			flag = hallet(i,j);
			if(flag) continue;
			p = line_intersection(L[i],L[j]);
			if(p == INF) continue;
			if(ESIT( max( abs(P[i].x-p.x) , abs(P[i].y-p.y) ) , max( abs(P[j].x-p.x) , abs(P[j].y-p.y) ) ))
			{
				t1 = max( abs(P[i].x-p.x) , abs(P[i].y-p.y) );
				int x = (int) p.x;
				int y = (int) p.y;
				if(!kont[mp3(x,y,t1)])
				{
					kont[mp3(x,y,t1)] = true;
					int m = ++T[(int)t1].mp[make_pair(x,y)];
					if(m == maxi) k = min(k,(int) t1);
					if(m > maxi)
					{
						maxi = m;
						k = (int) t1;
					}
				}
			}
		}
	}
	printf("%d\n%d\n",maxi+1,k);
}
int main()
{
	solve();
	return 0;
}
