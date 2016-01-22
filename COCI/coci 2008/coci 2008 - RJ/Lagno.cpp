#include <iostream>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define A(x,y) A[x][y]
#define MAXN 8
using namespace std;
int yon[8][2] = { {1,0},{1,1},{0,1},{-1,1},{-1,0},{-1,-1},{0,-1},{1,-1} };
char A[MAXN+5][MAXN+5];
int hesapla(int x,int y)
{
	int a,b,i,s(0),t;
	A(x,y) = 'B';
	FOR2(i,8)
	{
		a = x + yon[i][0];
		b = y + yon[i][1];
		t = 0;
		while(A(a,b) == 'W')
		{
			a+=yon[i][0];
			b+=yon[i][1];
			t++;
		}
		if(A(a,b) == 'B') s+=t;
	}
	A(x,y) = '.';
	return s;
}
void solve()
{
	int i,j,res(0);
	FOR2(i,MAXN)
		FOR2(j,MAXN)
			scanf(" %c",&A(i,j));
	FOR2(i,MAXN)
		FOR2(j,MAXN)
			if(A(i,j) == '.')
				res = max(res,hesapla(i,j));
	printf("%d\n",res);
}
int main()
{
	solve();
	return 0;
}
