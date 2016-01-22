#include <iostream>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define all(x) x.begin(),x.end()
#define MAXN 50
using namespace std;
class point
{
	public :
		int x,y;
		void read() { cin >> x >> y; }	
}alt[MAXN+5],p[MAXN+5],ust[MAXN+5];
bool cmp(const point &a,const point &b)
{
	return (a.x < b.x) || (a.x == b.x && a.y < b.y);
}
double ccw(point a,point b,point c)
{
	return (b.x-a.x)*(c.y-a.y) - (b.y-a.y)*(c.x-a.x);
}
void solve()
{
	point left,right,res;
	res.x =  1231231231;
	res.y = -1231231231;
	int K,N,a=0,i,j,u=0;
	double t;
	cin >> K >> N;
	FOR(i,1,N) p[i].read();
	sort(p+1,p+N+1,cmp);
	left = p[1];
	alt[a++] = left;
	ust[u++] = left;
	right = p[N];
	FOR(i,1,N)
	{
		t = ccw(left,p[i],right);
		if(i == N || t > 0)
		{
			while(u>=2 && ccw(ust[u-2],ust[u-1],p[i]) <= 0) u--;
			ust[u++] = p[i];
		}
		if(i == N || t < 0)
		{
			while(a>=2 && ccw(alt[a-2],alt[a-1],p[i]) >= 0) a--;
			alt[a++] = p[i];
		}
	}
	reverse(alt,alt+a);
	for(j=1,i=u; j<a; i++,j++)
		ust[i] = alt[j];
	u = i;
	for(i=1; i<u; i++)
		if(ust[i].y > res.y || (ust[i].y==res.y && ust[i].x < res.x))
			res = ust[i];
	for(i=1; i<u; i++)
		if(ust[i].x == res.x && ust[i].y == res.y)
			break;
	j = i;
	cout << K << " " << u-1 << endl;
	for(; i; i--)
		cout << ust[i].x << " " << ust[i].y << endl;
	for(i=u-1; i>j; i--)
		cout << ust[i].x << " " << ust[i].y << endl;
	for(i=0; i<a || i<u; i++)
		alt[i].x = alt[i].y = ust[i].x = ust[i].y = 0;
}
int main()
{
	int N,i;
	cin >> N;
	FOR(i,1,N)
		solve();
	return 0;
}
