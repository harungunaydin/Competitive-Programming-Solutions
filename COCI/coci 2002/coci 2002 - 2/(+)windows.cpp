#include <iostream>
#define KONTROL(a,b,c) (a<=c && b>=c)
#define FOR(i,a,b) for(i=a; i<=b; i++)
using namespace std;
class izracunajmiydineydiolebisiiste
{
	public:
		int x1,x2,y1,y2;
}A[100000];
int N,s;
bool hash[1000][1000],visited[1000];
int izracunaj(int x)
{
	visited[x]=true;
	int a,b,c,d,i,t=0,x1,y2;
	x1=A[x].x1; y2=A[x].y2;
	FOR(i,x+1,N)
	{
		a=A[i].x1;
		b=A[i].y1;
		c=A[i].x2;
		d=A[i].y2;
		if(!visited[i] && a<=x1 && c>=x1 && b<=y2 && d>=y2)
			t+=izracunaj(i);
	}
	return t+1;
}
void solve()
{
	int i,j;
	cin >> N;
	FOR(i,1,N)
		cin >> A[i].x1 >> A[i].y1 >> A[i].x2 >> A[i].y2;
	cout << izracunaj(1) << endl;
}
int main()
{
	solve();
	return 0;
}
