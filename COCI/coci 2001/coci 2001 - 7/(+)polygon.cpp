#include <iostream>
#define FOR(i,a,b) for(i=a; i<=b; i++)
using namespace std;
class polygon
{
	public:
		int x,y;
}A[105];
int N;
int DP[105][105];
bool cmp(const polygon &a1,const polygon &a2)
{
	return (a1.y*a2.x) < (a1.x*a2.y);
}
bool ccw(polygon p1,polygon p2,polygon p3)
{
	return p1.x*(p2.y-p3.y)+p2.x*(p3.y-p1.y)+p3.x*(p1.y-p2.y)>0;
}
int izracunaj(int x,int y)
{
	if(DP[x][y]) return DP[x][y];
	if(y==N) return 1;
	int i,maxi=-1000;
	FOR(i,y+1,N)
		if(ccw(A[i],A[x],A[y]))
			maxi=max(maxi,izracunaj(y,i)+1);
	return DP[x][y]=maxi;
}
void solve()
{
	int i,maxi=0;
	cin >> N;
	FOR(i,1,N)
		cin >> A[i].x >> A[i].y;
	sort(A+1,A+N+1,cmp);
	A[i].x=A[i].y=A[0].x=A[0].y=0;
	N++;
	FOR(i,1,N-1)
		maxi=max(maxi,izracunaj(0,i));
	cout << maxi << endl;
}
int main()
{
	solve();
	return 0;
}
