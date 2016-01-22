#include <algorithm>
#include <cstdio>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define TFOR(i,a,b) for(i=a; i>=b; i--)
#define all(x) x.begin(),x.end()
#define MAXN 
using namespace std;
void solve()
{
	double a1,a2,b1,b2,c1,c2;
	scanf("%lf %lf %lf",&a1,&b1,&c1);
	scanf("%lf %lf %lf",&a2,&b2,&c2);

	double mini = a1 / a2;
	mini = min( mini , b1/b2 );
	mini = min( mini , c1/c2 );

	printf("%.6lf %.6lf %.6lf\n" , a1 - a2*mini , b1 - b2*mini , c1 - c2*mini );

}
int main()
{
	solve();
	return 0;
}
