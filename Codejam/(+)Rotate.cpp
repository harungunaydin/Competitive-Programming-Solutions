#include <iostream>
#include <cstdio>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define TFOR(i,a,b) for(i=a; i>=b; i--)
#define MAXN 55
using namespace std;
string res;
int K,	N;
char A[MAXN][MAXN];
void hallet(int x,int y)
{
	if(res.empty()) res = (A[x][y] == 'R') ? "Red" : "Blue";
	else
	{
		if(res == "Red" && A[x][y] == 'B') res = "Both";
		if(res == "Blue" && A[x][y] == 'R') res = "Both";
	}
}
void solve()
{
	res = "";
	int i,j,k,x,y;
	scanf("%d %d",&N,&K);
	FOR(i,1,N)
		FOR(j,1,N)
			scanf(" %c",A[i]+j);
	TFOR(i,N,1)
		TFOR(j,N,1)
			if(A[i][j] != '.')
			{
				k = j + 1;
				while(k <= N && A[i][k] == '.') k++;
				k--;
				swap(A[i][j],A[i][k]);
			}
	FOR(i,1,N)
		FOR(j,1,N)
		{
			if(A[i][j] == '.') continue;
			x = i; y = j;
			while(x >= 1 && A[x][y] == A[i][j]) x--;
			if(i - x >= K) hallet(i,j);
			x = i; y = j;
			while(y >= 1 && A[x][y] == A[i][j]) y--;
			if(j - y >= K) hallet(i,j);
			
			x = i; y = j;
			while(x <= N && A[x][y] == A[i][j]) x++;
			if(x - i >= K) hallet(i,j);
			
			x = i; y = j;
			while(y <= N && A[x][y] == A[i][j]) y++;
			if(y - j >= K) hallet(i,j);
			
			x = i; y = j;
			while(x >= 1 && y >= 1 && A[x][y] == A[i][j]) x--,y--;
			if(j - y >= K) hallet(i,j);
			
			x = i; y = j;
			while(x >= 1 && y <= N && A[x][y] == A[i][j]) x--,y++;
			if(y - j >= K) hallet(i,j);
			
			x = i; y = j;
			while(x <= N && y >= 1 && A[x][y] == A[i][j]) x++,y--;
			if(j - y >= K) hallet(i,j);
			
			x = i; y = j;
			while(x <= N && y <= N && A[x][y] == A[i][j]) x++,y++;
			if(y - j >= K) hallet(i,j);
			
			if(res == "Both") break;
		}
		if(res.empty()) res = "Neither";
		cout << res << endl;
}
int main()
{
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
	int T,i;
	scanf("%d",&T);
	FOR(i,1,T)
	{
		printf("Case #%d: ",i);
		solve();
	}
	getchar(); getchar();
	return 0;
}
