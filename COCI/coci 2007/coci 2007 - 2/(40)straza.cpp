#include <algorithm>
#include <cstdio>
#include <cmath>
#include <set>
#include <vector>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define f first
#define s second
#define EPS 1e-3
#define ESIT(a,b) ( abs(a-b) < EPS )
#define MAXN 22
using namespace std;
typedef pair < int , int > pii;
class point
{
	public:
		double x,y;
		point() { x = y = 0; }
		point(double a,double b) { x = a; y = b; }
		void read() { scanf("%lf %lf",&x,&y); }
		void print() { printf("%.1lf %.1lf\n" , x , y ); }
		void set(double a,double b) { x = a; y = b; }
}P[MAXN*MAXN] , P3[5];

point make_point(double x,double y)
{
	point p(x,y);
	return p;
}

class segment
{
	public:
		point p1,p2;
		segment() {  }
		void read() { p1.read(); p2.read(); }
		void set(point a,point b) { p1 = a; p2 = b; }
}S[MAXN];

class line
{
	public:
		double a,b,c;
		line() { a = b = c = 0; }
		line(double x,double y,double z) { a = x; b = y; c = z; }
		void set( double x,double y,double z ) { a = x; b = y; c = z; }
};

line make_line( double a,double b,double c )
{
	line l(a,b,c);
	return l;
}

pii P2[MAXN*MAXN];

int K,N;

line segment_to_line( segment s )
{

	if( s.p1.x == s.p2.x ) return make_line( 1,0, -s.p2.x );
	
	double m = ( s.p2.y - s.p1.y ) / ( s.p2.x - s.p1.x );
	double n = s.p1.y - m*s.p1.x;

	return make_line(m,-1,n);

}

point line_intersection( line l1 , line l2 )
{
	double det = (l1.a * l2.b - l1.b * l2.a);

	return make_point( -(l1.c*l2.b - l1.b*l2.c) / det , -(l1.a*l2.c - l1.c*l2.a) / det );

}
bool is_point_in_segment( point p , segment s )
{

	if( p.x < min(s.p1.x,s.p2.x) || p.x > max(s.p1.x,s.p2.x) ) return false;

	if( p.y < min(s.p1.y,s.p2.y) || p.y > max(s.p1.y,s.p2.y) ) return false;

	return true;

}
point segment_intersection( segment s1 , segment s2 , pii k )
{

	line l1 = segment_to_line( s1 );

	line l2 = segment_to_line( s2 );

	if( (!l1.b && !l2.b) || l1.a * l2.b == l2.a * l1.b )
	{

		if( !is_point_in_segment(s1.p1 , s2) && !is_point_in_segment(s1.p2 , s2) ) return make_point(1000000,1000000);

		if( is_point_in_segment(s1.p1 , s2) )
		{
			P[++K] = s1.p1;
			P2[K] = k;
			if(is_point_in_segment(s2.p2 , s1) ) return s2.p2;
			else return s2.p1;
		}
		else
		{
			P[++K] = s1.p2;
			P2[K] = k;
			if(is_point_in_segment( s2.p1 , s1 )) return s2.p1;
			else return s2.p2;
		}

	}

	point p = line_intersection( l1 , l2 );

	if( !is_point_in_segment(p,s1) || !is_point_in_segment(p,s2) ) return make_point(1000000,1000000);

	return p;

}
bool operator == (point p1,point p2)
{
	return ESIT(p1.x,p2.x) && ESIT(p1.y,p2.y);
}
bool operator < ( point a , point b )
{
	if(a.x < b.x) return true;
	if(a.x > b.x) return false;
	return a.y < b.y;
}
double ccw( point a , point b , point c )
{
	return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
}
bool cmp( point a , point b )
{
	return a < b;
}
class ucnokta
{
	public:
		point p1,p2,p3;
		ucnokta() {  }
		void set(point a,point b,point c) { p1 = a; p2 = b; p3 = c; }

};

vector < ucnokta > RES;

int solve()
{
	int i,j,k,s(0);

	scanf("%d",&N);

	FOR(i,1,N)
	{
		S[i].read();
		FOR(j,1,i-1)
		{
			pii tmp = make_pair( i , j );

			point p = segment_intersection( S[i] , S[j] , tmp );

			if(p.x < 1000000)
			{
				P[++K] = p;
				P2[K] = tmp;
			}
		}
	}

	set < int > st;

	if(K < 3) return 0;

	FOR(i,1,K)
		FOR(j,i+1,K)
			FOR(k,j+1,K)
			{
				st.clear();
				st.insert( P2[i].f ); st.insert( P2[i].s );
				st.insert( P2[j].f ); st.insert( P2[j].s );
				st.insert( P2[k].f ); st.insert( P2[k].s );

				if( (int) st.size() == 3 && !ESIT( ccw( P[i] , P[j] , P[k]) , 0 ) )
				{
					P3[1] = P[i];
					P3[2] = P[j];
					P3[3] = P[k];
					if(P3[2] < P3[1]) swap(P3[1],P3[2]);
					if(P3[3] < P3[1]) swap(P3[1],P3[3]);
					if(P3[3] < P3[2]) swap(P3[2],P3[3]);
					ucnokta tmp;
					tmp.set(P3[1],P3[2],P3[3]);
					RES.push_back(tmp); 
				}
			}

	int res(1);

	FOR(i,1,(int)RES.size()-1)
		if( RES[i].p1 == RES[i-1].p1 && RES[i].p2 == RES[i-1].p2 && RES[i].p3 == RES[i-1].p3)
			continue;
		else res++;

	return res;

}
int main()
{
	printf("%d\n" , solve() );
	return 0;
}
