#include <iostream>
#include <cmath>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define f first
#define s second
#define EPS 0.000000001
#define ESIT(a,b) (abs((a)-(b)) < EPS)
#define MAXN 100
using namespace std;
int N;
class point
{
	public:
		double x,y;
		point() { x = y = 0; }
		void read() { scanf("%lf %lf",&x,&y); }
}A,B,C;
double ccw(point a,point b,point c)
{
	return (b.x-a.x)*(c.y-a.y) - (b.y-a.y)*(c.x-a.x);
}
bool hesapla(point T)
{
	double a,b,c;
	a = ccw(A,B,T);
	b = ccw(B,C,T);
	c = ccw(C,A,T);
	if(a < 0 && b < 0 && c < 0) return 1;
	if(a > 0 && b > 0 && c > 0) return 1;
	if(ESIT(a,0) && ESIT(b,0) ) return 1;
	if(ESIT(b,0) && ESIT(c,0) ) return 1;
	if(ESIT(c,0) && ESIT(a,0) ) return 1;
	if(((a<0) == (b<0)) && ESIT(c,0)) return 1;
	if(((b<0) == (c<0)) && ESIT(a,0)) return 1;
	if(((c<0) == (a<0)) && ESIT(b,0)) return 1;
	return 0;
}
void solve()
{
	point P;
	int i,res(0),x,y;
	A.read(); B.read(); C.read();
	scanf("%d",&N);
	FOR(i,1,N)
	{
		P.read();
		res+=hesapla(P);
	}
	printf("%.1lf\n",abs(A.x*(B.y-C.y) + B.x*(C.y-A.y) + C.x*(A.y-B.y))/2);
	printf("%d\n",res);
}
int main()
{
	solve();
	return 0;
}
