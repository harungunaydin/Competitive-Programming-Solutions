#include <iostream>
#include <cmath>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define all(x) x.begin(),x.end()
#define MAXN 1000
#define f first
#define s second
using namespace std;
typedef pair <double,double> pii;
pii alt[MAXN+5],ust[MAXN+5],p[MAXN+5];
double area(pii a,pii b,pii c)
{
	return (b.f-a.f)*(c.s-a.s) - (b.s-a.s)*(c.f-a.f);
}
double Distance(pii a,pii b)
{
	return sqrt((b.f-a.f)*(b.f-a.f) + (b.s-a.s)*(b.s-a.s));
}
void solve()
{
	pii left,right;
	int N,a=0,i,u=0;
	double res=0;
	cin >> N;
	FOR(i,1,N)
		cin >> p[i].f >> p[i].s;
	sort(p+1,p+N+1);
	alt[a++] = ust[u++] = left = p[1];
	right = p[N];
	FOR(i,1,N)
	{
		if(i == N || area(left,p[i],right) > 0)
		{
			while(u>=2 && area(ust[u-2],ust[u-1],p[i]) < 0) u--;
			ust[u++] = p[i];
		}
		if(i == N || area(left,p[i],right) < 0)
		{
			while(a>=2 && area(alt[a-2],alt[a-1],p[i]) > 0) a--;
			alt[a++] = p[i];
		}
	}
	reverse(alt,alt+a);
	FOR2(i,u-1)
		res+=Distance(ust[i],ust[i+1]);
	FOR2(i,a-1)
		res+=Distance(alt[i],alt[i+1]);
	printf("%.1lf\n",res);
}
int main()
{
	solve();
	return 0;
}
