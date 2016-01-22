#include <iostream>
#include <cstdio>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define INF 2000000000
#define MAXN 10
using namespace std;
char A[MAXN+5][MAXN+5];
void solve()
{
	register int i,j,s,res(INF);
	register char a,b,c;
	FOR(i,1,6)
		FOR(j,1,9)
			scanf(" %c",A[i]+j);
	FOR(a,0,'z')
		FOR(b,0,'z')
			FOR(c,0,'z')
			if(a != b && b != c)
			{
					s = 0;
					FOR(i,1,9)
						s+=(A[1][i] != a) + (A[2][i] != a);
					FOR(i,1,9)
						s+=(A[3][i] != b) + (A[4][i] != b);
					FOR(i,1,9)
						s+=(A[5][i] != c) + (A[6][i] != c);
					if(s < res) res = s;
					s = 0;
					FOR(i,1,6)
						s+=(A[i][1] != a) + (A[i][2] != a) + (A[i][3] != a);
					if(s > res) continue;
					FOR(i,1,6)
						s+=(A[i][4] != b) + (A[i][5] != b) + (A[i][6] != b);
					if(s > res) continue;
					FOR(i,1,6)
						s+=(A[i][7] != c) + (A[i][8] != c) + (A[i][9] != c);
					if(s < res) res = s;
				}
	printf("%d\n",res);
}
int main()
{
	solve();
	return 0;
}
