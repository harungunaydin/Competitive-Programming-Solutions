#include <iostream>
#include <vector>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define TFOR(i,a,b) for(i=a; i>=b; i--)
#define all(x) x.begin(),x.end()
#define INF 2000000000
#define MAXN 300000
using namespace std;
class point
{
	public:
		double x,y;
		point() { x = y = 0; } 
		point read() { scanf("%lf %lf",&x,&y); return *this;}
};
vector < point > P;
point C[MAXN+5],alt[MAXN+5],ust[MAXN+5];
int SC,N,a,u;
double ccw(point a,point b,point c)
{
	return (a.x-b.x)*(a.y-c.y) - (a.y-b.y)*(a.x-c.x);
}
void convex_hull()
{
	vector < point > :: iterator it,it2;
	int i;
	SC = a = u = 0;
	point left,right;
	left = P[0];
	right = P[P.size()-1];
	ust[u++] = alt[a++] = left;
	for(it = P.begin(); it!=P.end(); ++it)
		cout << it->x << " " << it->y << endl;
	cout << endl << endl;
	for(it = P.begin(); it != P.end(); ++it)
	{
		it2 = it;
		it2++;
		if(it2 == P.end() || ccw(left,right,*it) > 0)
		{
			while(u>=2 && ccw(ust[u-2],ust[u-1],*it) > 0) u--;
			ust[u++] = *it;
		}
		else
		{
			while(a>=2 && ccw(alt[a-2],alt[a-1],*it) < 0) a--;
			alt[a++] = *it;
		}
	}
	FOR2(i,u)
		C[SC++] = ust[i];
	TFOR(i,a-1,2)
		C[SC++] = alt[i];
}
double area()
{
	
}
void Delete(char c)
{
	vector < point > :: iterator it,it2;
	double minx(INF),maxx(-INF),miny(INF),maxy(-INF);
	if(c == 'R')
	{
		for(it = P.begin(); it!=P.end(); ++it)
			if(it->x > maxx)
			{
				maxx = it->x;
				it2 = it;
			}
	}
	else if(c == 'L')
	{
		for(it = P.begin(); it!=P.end(); ++it)
			if(it->x < minx)
			{
				minx = it->x;
				it2 = it;
			}
	}
	else if(c == 'U')
	{
		for(it = P.begin(); it!=P.end(); ++it)
			if(it->y > maxy)
			{
				maxy = it->y;
				it2 = it;
			}
	}
	else if(c == 'D')
	{
		for(it = P.begin(); it!=P.end(); ++it)
			if(it->y < miny)
			{
				miny = it->y;
				it2 = it;
			}
	}
	P.erase(it2);
}
void solve()
{
	point p;
	int a,b,i;
	char c;
	scanf("%d",&N);
	FOR(i,1,N)
		P.push_back(p.read());
	i = 0;
	while(i<N-2)
	{
		scanf(" %c",&c);
		Delete(c);
		convex_hull();
		printf("%.1lf\n",area());
	}
}
int main()
{
	solve();
	system("PAUSE");
	return 0;
}
