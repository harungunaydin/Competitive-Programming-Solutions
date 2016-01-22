#include <cmath>
#include <cstdio>
#define FOR(i,a,b) for(i=a; i<=b; i++)
using namespace std;
double c,x,y;

double hesapla(double k)
{
	double m1 = sqrt( x * x - k * k ) / k , n1 = 0;
	double m2 = - sqrt( y * y - k * k ) / k , n2 = sqrt( y * y - k * k );

	return (- m1 * n2 ) / ( m2 - m1 );
}

double BS(double bas , double son , int t)
{
	if(t == 25) return bas;

	double orta = ( bas + son ) / 2;

	return hesapla(orta) < c ? BS(bas,orta,t+1) : BS(orta,son,t+1);
}
int main()
{
	int T,i;
	scanf("%d",&T);
	FOR(i,1,T)
	{
		scanf("%lf %lf %lf",&x,&y,&c);
		printf("Case %d: %.6lf\n",i , BS(0.0,(x<y)?x:y,0));
	}
	return 0;
}
