#include <iostream>
#include <cmath>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define MAXN 100000
#define f first
#define s second
using namespace std;
typedef pair <int,int> pii;
pii p[MAXN+5];
bool ccw(pii a,pii b,pii c)
{
	return (b.f-a.f)*(c.s-a.s) - (b.s-a.s)*(c.f-a.f) < 0;
}
string solve()
{
	int N,a,b,c,d,e,f,i,res=0;
	double u1,u2,u3,k,t;
	cin >> N;
	FOR(i,1,N)
		cin >> p[i].f >> p[i].s;
	p[N+1] = p[1];
	p[N+2] = p[2];
	FOR(i,1,N)
		res+=ccw(p[i],p[i+2],p[i+1]);
	return (!res || res == N) ? "YES" : "NO";
}
int main()
{
	cout << solve() << endl;
	return 0;
}
