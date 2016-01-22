#include <algorithm>
#include <cstdio>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define TFOR(i,a,b) for(i=a; i>=b; i--)
#define MAXN 55
using namespace std;
typedef pair < int , int > pii;
pii P[15];
int K,M,N;
int RES[MAXN];
char A[MAXN][MAXN];
void solve()
{
	int i,j,s(0);
	scanf("%d %d",&M,&N);

	FOR(i,1,M)
		scanf("%s" , A[i] + 1 );

	FOR(i,1,M)
		TFOR(j,N,1)
			if( '0' <= A[i][j] && A[i][j] <= '9' )
			{
				P[++K] = make_pair( N-j , A[i][j] - '0' );
				break;
			}

	sort( P+1 , P+K+1 );

	FOR(i,1,K)
	{
		j = i;
		s++;
		while(i <= K && P[i].first == P[j].first) RES[ P[i++].second ] = s;
		i--;
	}

	FOR(i,1,9)
		printf("%d\n" , RES[i] );

}
int main()
{
	solve();
	return 0;
}
