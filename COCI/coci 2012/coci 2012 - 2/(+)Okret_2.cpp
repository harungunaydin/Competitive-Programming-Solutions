#include <iostream>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define all(x) x.begin(),x.end()
#define MAXN 10
using namespace std;
char A[MAXN+5][MAXN+5];
int yon[4][2] = { {1,0},{0,1},{-1,0},{0,-1} };
bool solve()
{
	int M,N,i,j,k,s;
	scanf("%d %d",&M,&N);
	FOR(i,1,M)
		FOR(j,1,N)
			scanf(" %c",A[i]+j);
	FOR(i,1,M)
		FOR(j,1,N)
			if(A[i][j] == '.')
			{
				s = 0;
				FOR2(k,4)
					s+=(A[i+yon[k][0]][j+yon[k][1]] != '.');
				if(s>=3) return 1;
			}
	return 0;
}
int main()
{
	cout << solve() << endl;
	return 0;
}
