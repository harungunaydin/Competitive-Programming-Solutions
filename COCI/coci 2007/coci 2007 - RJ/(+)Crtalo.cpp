#include <iostream>
#include <cstdio>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define KONTROL(x,y) (x >= 1 && x <= N && y >= 1 && y <= N)
#define MAXN 100
using namespace std;
char A[MAXN+5][MAXN+5];
void solve()
{
	int i,j,N,x(1),y(1);
	char c;
	scanf("%d",&N);
	FOR(i,1,N)
		FOR(j,1,N)
			A[i][j] = '.';
	string str;
	cin >> str;
	FOR2(i,str.size())
	{
		if(str[i] == 'D' && KONTROL(x+1,y))
		{
			A[x][y] = (A[x][y] == '.' || A[x][y] == '|') ? '|' : '+';
			x++;
			A[x][y] = (A[x][y] == '.' || A[x][y] == '|') ? '|' : '+';
		}
		else if(str[i] == 'R' && KONTROL(x,y+1))
		{
			A[x][y] = (A[x][y] == '.' || A[x][y] == '-') ? '-' : '+';
			y++;
			A[x][y] = (A[x][y] == '.' || A[x][y] == '-') ? '-' : '+';
		}
		else if(str[i] == 'U' && KONTROL(x-1,y))
		{
			A[x][y] = (A[x][y] == '.' || A[x][y] == '|') ? '|' : '+';
			x--;
			A[x][y] = (A[x][y] == '.' || A[x][y] == '|') ? '|' : '+';
		}
		else if(str[i] == 'L' && KONTROL(x,y-1))
		{
			A[x][y] = (A[x][y] == '.' || A[x][y] == '-') ? '-' : '+';
			y--;
			A[x][y] = (A[x][y] == '.' || A[x][y] == '-') ? '-' : '+';
		}
	}
	for(i=1; i<=N; i++,printf("\n"))
		FOR(j,1,N)
			printf("%c",A[i][j]);
}
int main()
{
	solve();
	return 0;
}
