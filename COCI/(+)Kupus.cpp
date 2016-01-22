#include <iostream>
#include <cstdio>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define MAXN 1000
#define PI 3.141591
using namespace std;
int A[MAXN+5][MAXN+5];
bool B[MAXN+5][MAXN+5];
void solve()
{
	int N,X,Y,a,b,i,j;
	double res;
	res = 0;
	scanf("%d %d",&X,&Y);
	scanf("%d",&N);
	FOR(i,1,N)
	{
		scanf("%d %d",&a,&b);
		B[a][b] = true;
		if(a > 0 && b > 0)
			A[a-1][b-1]++;
		if(b > 0)
			A[a][b-1]++;
		if(a > 0)
			A[a-1][b]++;
		A[a][b]++;
	}
	getchar(); getchar();
	FOR2(i,X)
		FOR2(j,Y)
			if(A[i][j] > 2)
				res = res + 1.0;
			else if(A[i][j] == 2)
				res+=((B[i][j] && B[i+1][j+1]) || (B[i][j+1] && B[i+1][j])) ? 1.0 : (5.054816 - PI)/2.0;
			else if(A[i][j] == 1)
				res+=PI/4.0;
	printf("%.6lf\n",res);
}
int main()
{
	solve();
	return 0;
}
