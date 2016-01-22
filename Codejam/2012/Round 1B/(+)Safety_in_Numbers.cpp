#include <cstdio>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define MAXN 201
using namespace std;
double T;
int N;
int A[MAXN];
bool control(int x,double t)
{
	double d = 100 - t , k , p = A[x] + (t * T) / 100;
	int i;

	FOR(i,1,N)
		if(i != x && A[i] < p)
		{
			k = ( 100 * (p - A[i]) ) / T;
			if(k > d) return true;
			d -= k;
		}

	return false;
}
double BS(double bas , double son,int x,int t)
{
	if((bas > son) ? bas - son : son - bas < 1e-6) return bas;
	double orta = ( bas + son ) / 2;

	return control(x,orta) ? BS(bas,orta,x,t+1) : BS(orta,son,x,t+1);
}
void solve()
{
	T = 0;
	int i;
	scanf("%d",&N);
	FOR(i,1,N) { scanf("%d",A+i); T += A[i]; }

	FOR(i,1,N)
		printf("%.6lf " , BS(0.0,100.0,i,0) );
	printf("\n");
}
int main()
{
	int T,i;
	scanf("%d",&T);
	FOR(i,1,T)
	{
		printf("Case #%d: ",i);
		solve();
	}
	return 0;
}
