#include <iostream>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define all(x) x.begin(),x.end()
using namespace std;
class point
{
	public:
		int x,y;
		void read() { cin >> x >> y; }
};
double Distance(point a,point b)
{
	return (b.x-a.x)*(b.x-a.x) + (b.y-a.y)*(b.y-a.y);
}
void solve()
{
	point A,B,C,D;
	double ab,ac,ad,bc,bd,cd;
	A.read(); B.read(); C.read(); D.read();
	ab = Distance(A,B);
	ac = Distance(A,C);
	ad = Distance(A,D);
	bc = Distance(B,C);
	bd = Distance(B,D);
	cd = Distance(C,D);
	printf("%d\n",(ab+bc==ac) + (bc+cd==bd) + (cd+ad==ac) + (ad+ab==bd));
}
int main()
{
	solve();
	return 0;
}
