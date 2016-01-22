#include <iostream>
#include <cmath>
#include <cstdio>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define MAXN 100000
using namespace std;
int N;
double K;
double A[MAXN+5];
bool control(double t)
{
	int i;
	double pos = A[1] + t;
	FOR(i,2,N)
	{
		if(pos + K < A[i] - t) return 0;
		pos = min( pos + K , A[i] + t );
	}
	return 1;
}
double BS(double bas,double son)
{
	double orta = (bas + son)/2;
	if(son - bas < 0.00000001) return control(bas) ? bas : son;
	return control(orta) ? BS(bas,orta) : BS(orta,son);
}
void solve()
{
	int i;
	scanf("%lf",&K);
	scanf("%d",&N);
	FOR(i,1,N) scanf("%lf",A+i);
	printf("%.3lf\n",BS(0.0,1e9));
}
int main()
{
	solve();
	return 0;
}
