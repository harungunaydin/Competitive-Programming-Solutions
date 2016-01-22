#include <iostream>
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
}p[MAXN+5];
void solve()
{
	int N,i;
	while(!cin.eof())
	{
		cin >> N;
		if(cin.eof()) break;
		FOR(i,1,N)
			p[i].read();
		p[N+1] = p[1];
		printf("%d",N);
		FOR(i,1,N)
			printf(" %.6lf %.6lf",(p[i].x+p[i+1].x)/2,(p[i].y+p[i+1].y)/2);
		printf("\n");
	}
}
int main()
{
	solve();
	return 0;
}
