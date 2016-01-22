#include <iostream>
#include <cstdio>
#include <cmath>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define EPS 1e-12
#define ESIT(a,b) ( abs(a-b) < EPS )
#define MAXN 205
using namespace std;
long double D;
int N;
long double S[MAXN],X[MAXN];
bool control(long double t)
{
	long double last = X[1] - t + ( S[1] - 1 ) * D;
	if(abs(last - X[1]) > t) return false;
	int i;
	FOR(i,2,N)
	{
		long double bas = max( last + D , X[i] - t );
		last = bas + D * ( S[i] - 1 );
		if(abs(last - X[i]) > t) return false;
	}
	return true;
}
long double BS(long double bas,long double son,int s)
{

	if(s > 10005) return bas;
	long double orta = ( bas + son ) / 2;

	return control(orta) ? BS(bas,orta,s+1) : BS(orta,son,s+1);
}
void solve()
{
	int i;
	scanf("%d %Lf",&N,&D);
	FOR(i,1,N)
		scanf("%Lf %Lf",X+i,S+i);
	printf("%Lf\n",BS(0,1e12,0) );
}
int main()
{
	freopen("inp","r",stdin);
	freopen("out","w",stdout);
	int T,i;
	scanf("%d",&T);
	FOR(i,1,T)
	{
		printf("Case #%d: ",i);
		solve();
	}
	return 0;
}
