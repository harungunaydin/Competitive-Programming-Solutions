#include <algorithm>
#include <cstdio>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define TFOR(i,a,b) for(i=a; i>=b; i--)
#define f first
#define s second
#define KONTROL(x,y) ( 1 <= x && x <= N && y <= 1 && y <= N && A[x][y] != '.' )
#define all(x) x.begin(),x.end()
#define MAXN 105
using namespace std;
typedef pair < int , int > pii;
pii P[MAXN*MAXN];
int K,N;
char A[MAXN][MAXN];
void solve()
{
	int i,j,k,res(0);
	scanf("%d",&N);
	FOR(i,1,N)
		FOR(j,1,N)
		{
			scanf(" %c" , A[i] + j );
			if(A[i][j] != '.')
				P[++K] = make_pair(i,j);
		}

	FOR(i,1,K)
		FOR(j,i+1,K)
			FOR(k,j+1,K)
				if((P[i].f - P[j].f) * (P[i].s - P[k].s) == (P[i].s - P[j].s) * (P[i].f - P[k].f))
					res++;

	printf("%d\n" , res );

}
int main()
{
	solve();
	return 0;
}
