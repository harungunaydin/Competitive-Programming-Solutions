#include <iostream>
#include <cstdio>
#include <cstring>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define MAX(a,b) ( (a) > (b) ? (a) : (b) )
#define MAXN 301
using namespace std;
inline int Max( int a , int b ) { return a > b ? a : b; }
int M,N,W;
int DP[MAXN],T[605];
char A[MAXN];
char B[605][105];
int dp(int x)
{
	int &ret = DP[x];
	if(ret != -1) return ret;
	if(x >= N) return ret = 0;
	ret = dp(x+1);
	int i,j,k;
	FOR(i,1,W)
	{
		j = x;
		k = 0;
		while(k < T[i] && j < N)
		{
			if(A[j] == B[i][k]) { k++; j++; }
			else j++;
		}
		if(k == T[i]) ret = Max( ret , dp(j) + k );
	}
	return ret;
}
void solve()
{
	memset( DP , -1 , sizeof DP );
	int i;
	scanf("%d %d",&W,&N);
	scanf("%s",A);
	FOR(i,1,W)
	{
		scanf("%s",B[i]);
		T[i] = strlen(B[i]);
	}
	printf("%d\n" , N - dp(0) );
}
int main()
{
	solve();
	return 0;
}
