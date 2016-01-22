#include <iostream>
#include <cstdio>
#include <cstring>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define MAXN 100001
using namespace std;
typedef pair < int , int > pii;
inline int Abs( int a ) { return a > 0 ? a : -a; }
inline int Min( int a , int b ) { return a < b ? a : b; }
inline int Max( int a , int b ) { return a > b ? a : b; }
int K,M,N;
int B[MAXN],DP[MAXN];
int A[51][11];
void solve()
{
	int i,j,k,t;
	scanf("%d %d %d",&K,&N,&M);
	FOR(i,1,K)
		FOR(j,1,N)
			scanf("%d",A[i]+j);
	FOR(i,1,N-1)
	{
		FOR(j,1,K)
			B[j] = A[j][i+1] - A[j][i];
		memset( DP , 0 , sizeof DP );
		FOR(j,1,K)
			if(B[j] > 0)
			{
				t = A[j][i];
				DP[t] = Max( DP[t] , B[j] );
				FOR(k,1,M)
					if(k+t <= M && DP[k] && ( DP[k] + B[j] > DP[k+t]) )
						DP[k+t] = DP[k] + B[j];
			}
		int maxi(0);
		FOR(j,1,M)
			if(DP[j])
				maxi = Max( maxi , j + DP[j] + ( M - j ) );
		M = maxi;
	}
	printf("%d\n" , M);
}
int main()
{
	solve();
	return 0;
}
