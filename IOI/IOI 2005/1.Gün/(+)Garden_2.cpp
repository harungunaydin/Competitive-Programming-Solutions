#include <cstdio>
#include <cstring>
#include <iostream>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define TFOR(i,a,b) for(i=a; i>=b; i--)
#define f first
#define s second
#define all(x) x.begin(),x.end()
#define H(x1,y1,x2,y2) ( A[x2][y2] - A[x2][y1-1] - A[x1-1][y2] + A[x1-1][y1-1] )
#define MAXN 255
using namespace std;
typedef pair < int , int > pii;
pii P[10005];
int K,M,N,S,res(1231231231);
int L[MAXN] , R[MAXN];
int A[MAXN][MAXN];
void read()
{
	int i;
	scanf("%d %d",&M,&N);
	scanf("%d %d",&S,&K);
	FOR(i,1,S)
		scanf("%d %d",&P[i].f,&P[i].s);
}
void solve()
{
	memset( A , 0  , sizeof A );
	memset( R , 15 , sizeof R );
	memset( L , 15 , sizeof L );
	int i,j,mini,t,x1,x2,y1,y2;
	FOR(i,1,S)
		A[P[i].f][P[i].s]++;

	FOR(i,1,M)
		FOR(j,1,N)
			A[i][j] += A[i-1][j] + A[i][j-1] - A[i-1][j-1];

	FOR(y1,1,N)
		FOR(y2,y1,N)
		{
			x1 = x2 = 1;
			mini = 123123123;
			while(1)
			{
				t = H(x1,y1,x2,y2);
				if(t < K) x2++;
				else if(t > K) x1++;
				else
				{
					mini = min( mini , 2 * ( x2 - x1 + 1 + y2 - y1 + 1 ) );
					x1++;
				}
				if(x1 > x2) x2++;
				if(x2 == M + 1) break;
			}
			if(mini < R[y1])
				R[y1] = mini;
			if(mini < L[y2])
				L[y2] = mini;
		}

	FOR(i,2,N)
		L[i] = min( L[i] , L[i-1] );

	TFOR(i,N-1,1)
		R[i] = min( R[i] , R[i+1] );

	FOR(i,1,N)
		res = min( res , L[i] + R[i+1] );

}
int main()
{
	read();
	solve();
	int i;
	swap(M,N);
	FOR(i,1,S)
		swap(P[i].f,P[i].s);
	solve();

	if(res > 100000000) printf("NO\n");
	else printf("%d\n" , res );

	return 0;
}
