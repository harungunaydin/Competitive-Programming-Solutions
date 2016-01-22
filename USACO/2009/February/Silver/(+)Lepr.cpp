#include <iostream>
#include <cstdio>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define TFOR(i,a,b) for(i=a; i>=b; i--)
#define F(x) ( (x + 1) % N )
#define INF 2000000000
#define MAXN 201
using namespace std;
int N,res(-INF);
int A[MAXN][MAXN];
int B[MAXN];
inline int G(int x) { return x > 0 ? x - 1 : N - 1; }
void kadane()
{
	int i,top,maxi;
	top = maxi = B[1];
	if(top < 0) top = 0;
	FOR(i,2,N)
	{
		top += B[i];
		if(top > maxi) maxi = top;
		if(top < 0) top = 0;
	}
	if(maxi > res) res = maxi;
}
void solve()
{
	int i,j,k,s(0),x,y;
	scanf("%d",&N);
	FOR2(i,N)
		FOR2(j,N)
		{
			scanf("%d",A[i]+j);
			if(A[i][j] > res) res = A[i][j];
		}

	FOR2(i,N)
	{
		FOR2(j,N)
		{
			s = 0;
			for(k = F(j); k != j ; k = F(k))
				B[++s] = A[i][k];
			B[++s] = A[i][j];
			kadane();
		}
	}
	FOR2(j,N)
		FOR2(i,N)
		{
			s = 0;
			for(k = F(i); k != i; k = F(k))
				B[++s] = A[k][j];
			B[++s] = A[i][j];
			kadane();
		}
	FOR2(i,N)
		FOR2(j,N)
		{
			s = 0;
			for( x = F(i) , y = F(j) ; x != i || y != j; x = F(x) , y = F(y) )
				B[++s] = A[x][y];
			B[++s] = A[i][j];
			kadane();
		}
	FOR2(i,N)
		FOR2(j,N)
		{
			s = 0;
			for( x = F(i) , y = G(j); x != i || y != j; x = F(x) , y = G(y) )
				B[++s] = A[x][y];
			B[++s] = A[i][j];
			kadane();
		}
	printf("%d\n" , res );
}
int main()
{
	solve();
	return 0;
}
