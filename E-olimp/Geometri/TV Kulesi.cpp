#include <iostream>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define all(x) x.begin(),x.end()
#define MAXN 100
using namespace std;
class point
{
	public:
		double x,y;
		int value;
		void read() { cin >> x >> y >> value; }
}p[MAXN+5];
int N,L;
double Distance(point a,point b)
{
	return (b.x-a.x)*(b.x-a.x) + (b.y-a.y)*(b.y-a.y);
}
int kontrol(int x)
{
	int i,res=0;
	FOR(i,1,N)
		if(Distance(p[x],p[i]) <= L*L)
			res+=p[i].value;
	return res;
}
void solve()
{
	int i,index,res=0,t;
	cin >> L >> N;
	FOR(i,1,N)
		p[i].read();
	FOR(i,1,N)
		if((t=kontrol(i)) > res)
		{
			res = t;
			index = i;
		}
	cout << res << " " << index << endl;
}
int main()
{
	solve();
	return 0;
}
