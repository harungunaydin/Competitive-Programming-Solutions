#include <cmath>
#include <cstdio>
#define FOR(i,a,b) for(i=a; i<=b; i++)
using namespace std;
class point
{
	public:
		long double x,y,z;
		point() { x = y = z = 0; }
		void read() { scanf("%Lf %Lf %Lf",&x,&y,&z); }
		point set(long double a,long double b,long double c) { x = a; y = b; z = c; return *this; }
}p;
long double Distance( point a ) { return a.x * a.x + a.y * a.y + a.z * a.z; }
long double tvx,tvy,tvz;
point f(long double t)
{
	point p1;
	return p1.set( p.x + t * tvx , p.y + t * tvy , p.z + t * tvz );
}
void solve()
{
	tvx = tvy = tvz = 0;
	long double vx,vy,vz,tx(0),ty(0),tz(0),x,y,z;
	int N,i;
	scanf("%d",&N);
	FOR(i,1,N)
	{
		scanf("%Lf %Lf %Lf %Lf %Lf %Lf",&x,&y,&z,&vx,&vy,&vz);
		tx += x; ty += y; tz += z;
		tvx += vx; tvy += vy; tvz += vz;
	}
	tvx /= N; tvy /= N; tvz /= N;
	p.set(tx/N,ty/N,tz/N);

	long double bas(0),son(50000000),ort1,ort2,t;

	FOR(i,1,100)
	{
		t = ( son - bas ) / 3;

		ort1 = bas + t;
		ort2 = bas + 2 * t;

		point p1 = f(ort1);
		point p2 = f(ort2);

		if(Distance(p1) > Distance(p2)) bas = ort1;
		else son = ort2;
	}

	printf("%.6Lf %.6Lf\n" , sqrt ( Distance( f(bas) ) ) , bas );
	
}
int main()
{
	int T,i;
	scanf("%d",&T);
	FOR(i,1,T)
	{
		printf("Case #%d: ",i);
		solve();
	}
	return 0;
}
