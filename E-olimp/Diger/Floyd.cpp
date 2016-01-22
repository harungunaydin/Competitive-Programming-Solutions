#include <iostream>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define all(x) x.begin(),x.end()
#define MAXN 2000
#define INF 100000000
using namespace std;
int N;
double A[MAXN+5][MAXN+5];
void read()
{
	int i,j;
	scanf("%d",&N);
	FOR(i,1,N)
		FOR(j,1,N)
		{
			scanf("%lf",&A[i][j]);
			if(A[i][j] == -1) A[i][j] = INF;
	}
}
void solve()
{
	int i,j,k;
	double res = -INF;
	FOR(k,1,N)
		FOR(i,1,N)
			FOR(j,1,N)
				A[i][j] = min(A[i][j],A[i][k] + A[k][j]);
	FOR(i,1,N)
		FOR(j,1,N)
			if(A[i][j] != INF)
				res = max(res,A[i][j]);
	cout << res << endl;
}
int main()
{
	read();
	solve();
	return 0;
}
