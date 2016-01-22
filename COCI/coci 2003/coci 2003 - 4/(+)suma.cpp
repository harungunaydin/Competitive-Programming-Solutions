#include <iostream>
#include <cmath>
#define FOR(_i,__a,___b) for(_i=__a; _i<=___b; _i++)
#define FOR2(_i,__n) FOR(_i,0,__n-1)
#define f first
#define s second
#define ll long long
#define ii pair < int,int >
using namespace std;
int N;
ll sonuc;
ii p[30005];
ll A[1005];
bool cmp(const ii &a,const ii &b)
{
	return atan2(a.s,a.f)-atan2(b.s,b.f)<0.000001;
}
void read()
{
	int i;
	cin >> N;
	FOR2(i,N)
		cin >> p[i].f >> p[i].s;
}
ll agirlik(ll a,ll b)
{
	return a*a+b*b;
}
void solve()
{
	int i=0,j=0;
	double PI=acos(-1);
	bool b=false;
	ii top;
	sort(p,p+N,cmp);
	top.f=p[0].f;
	top.s=p[0].s;
	sonuc=agirlik(p[0].f,p[0].s);
	while(true)
	{
		if(++j==N) { j=0; b=true; }
		while(atan2(p[j].s,p[j].f)-atan2(p[i].s,p[i].f)+2*b*PI>PI)
		{
			top.f-=p[i].f; top.s-=p[i].s;
			sonuc>?=agirlik(top.f,top.s);
			if(++i==N) return;
		}
		top.f+=p[j].f; top.s+=p[j].s;
		sonuc>?=agirlik(top.f,top.s);
	}
}
int main()
{
	read();
	solve();
	cout << sonuc << endl;
	return 0;
}
