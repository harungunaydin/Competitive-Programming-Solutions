#include <iostream>
#include <cmath>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define T(x,c) (A[(N)][(c)] - A[((x)-1)][(c)])
#define MAXN 100000
using namespace std;
int N,SX,SY,TX,TY,X,Y;
int B[MAXN+5];
int A[MAXN+5][10],yon[8][2] = { {0,1},{-1,1},{-1,0},{-1,-1},{0,-1},{1,-1},{1,0},{1,1} };
double hesapla(int a,int t)
{
	int b,i,x,y;
	b = (B[a] + t)%8;
	x = X + yon[b][0]; y = Y + yon[b][1];
	FOR2(i,8)
	{
		x+=T(a+1,i) * yon[(i+t)%8][0];
		y+=T(a+1,i) * yon[(i+t)%8][1];
	}
	return double(x - TX) * double(x - TX) + double(y - TY) * double(y - TY);
}
void solve()
{
	double res;
	res = 100000000;
	res*=100000;
	int i,j,k(0);
	char c;
	scanf("%d %d %d %d %d",&SX,&SY,&TX,&TY,&N);
	X = SX; Y = SY;
	FOR(i,1,N)
	{
		scanf(" %c",&c);
		c-='0';
		k = (k + c)%8;
		B[i] = k;
		FOR2(j,8)
			A[i][j] = A[i-1][j] + (k == j);
	}
	FOR(i,1,N)
	{
		FOR2(j,8)
			res = min(res,hesapla(i,j));
		X+=yon[B[i]][0];
		Y+=yon[B[i]][1];
	}
	printf("%llf\n",sqrt(res));
}
int main()
{
	solve();
	return 0;
}
