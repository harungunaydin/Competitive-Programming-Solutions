#include <iostream>
#include <cstdio>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define TFOR(i,a,b) for(i=a; i>=b; i--)
#define MAXN 105
using namespace std;
typedef pair < int , int > pii;
int N;
char A[MAXN][MAXN];
double WP(int x)
{
	int i,s(0),t(0);
	FOR(i,1,N)
		if(A[x][i] == '1')
			s++;
		else if(A[x][i] == '0')
			t++;
	return (double)(s) / (s + t);
}
double OWP(int x)
{
	double s(0);
	int i,j,s2(0),t,t2;
	FOR(i,1,N)
		if(A[x][i] != '.')
		{
			t = t2 = 0;
			FOR(j,1,N)
				if(j != x)
				{
					if(A[i][j] == '1') t++;
					if(A[i][j] == '0') t2++;
				}
			s += (double)(t) / (t + t2);
			s2++;
		}
	return s / s2;
}
double OOWP(int x)
{
	double s(0);
	int i,s2(0);
	FOR(i,1,N)
		if(A[x][i] != '.')
		{
			s += OWP(i);
			s2++;
		}
	return s / s2;
}
void solve()
{
	int i,j;
	scanf("%d",&N);
	FOR(i,1,N)
		FOR(j,1,N)
			scanf(" %c",A[i]+j);
	FOR(i,1,N)
		printf("%lf\n" , 0.25 * WP(i) + 0.5 * OWP(i) + 0.25 * OOWP(i) );
}
int main()
{
	freopen("inp","r",stdin);
	freopen("out","w",stdout);
	int T,i;
	scanf("%d",&T);
	FOR(i,1,T)
	{
		printf("Case #%d:\n",i);
		solve();
	}
	return 0;
}
