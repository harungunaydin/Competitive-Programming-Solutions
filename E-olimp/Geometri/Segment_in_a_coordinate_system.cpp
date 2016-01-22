#include <iostream>
#include <cmath>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define all(x) x.begin(),x.end()
using namespace std;
int A[5];
int bolge(double x,double y)
{
	if(x > 0 && y > 0) return 1;
	if(x < 0 && y > 0) return 2;
	if(x < 0 && y < 0) return 3;
	if(x > 0 && y < 0) return 4;
	return 0;
}
void solve()
{
	int i;
	double b1,b2,c1,c2,x1,y1,x2,y2;
	cin >> x1 >> y1 >> x2 >> y2;
	b1 = (x2-x1)/1000;
	b2 = (y2-y1)/1000;
	c1 = x1;
	c2 = y1;
	if(x1 == x2 && y1 == y2) { cout << bolge(x1,y1) << endl; exit(0); }
	FOR(i,1,1000)
	{
		A[bolge(c1,c2)]++;	
		c1+=b1;
		c2+=b2;
	}
	FOR(i,1,4)
		if(A[i])
			cout << i << endl;
	if(!A[1] && !A[2] && !A[3] && !A[4]) cout << 0 << endl;
}
int main()
{
	solve();
	return 0;
}
