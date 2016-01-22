#include <cmath>
#include <cstdio>
using namespace std;
void solve()
{
	double r;
	scanf("%lf",&r);
	printf("%lf\n" , acos(-1) * r * r );
	printf("%lf\n" , 2 * r * r );
}
int main()
{
	solve();
	return 0;
}
