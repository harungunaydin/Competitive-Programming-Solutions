#include <iostream>
#include <cmath>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define all(x) x.begin(),x.end()
#define MAXN 10000
using namespace std;
class point
{
	public:
		double x,y;
		void read() { cin >> x >> y; }
}p[MAXN+5],res[MAXN+5];
int N;
void solve()
{
	int N,i;
	double a,b,tx,ty;
	while(!cin.eof())
	{
		tx = ty = 0;
		cin >> N;
		if(cin.eof()) break;
		FOR(i,1,N)
		{
			p[i].read();
			tx+=p[i].x;
			ty+=p[i].y;
		}
		for(i=2; i<=N; i+=2)
		{
			tx-=2*p[i].x;
			ty-=2*p[i].y;
		}
		res[1].x = tx; res[1].y = ty;
		FOR(i,1,N)
		{
			res[i+1].x = 2*p[i].x - res[i].x;
			res[i+1].y = 2*p[i].y - res[i].y;
		}
		printf("%d",N);
		FOR(i,1,N)
			printf(" %.6lf %.6lf",res[i].x,res[i].y);
		printf("\n");
	}
}
int main()
{
	solve();
	return 0;
}
