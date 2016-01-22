#include <iostream>
#include <cstdio>
#include <cstring>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define f first
#define s second
#define MAXN 2005
using namespace std;
typedef pair < int , int > pii;
inline int Min( int a , int b ) { return a < b ? a : b; }
pii C[300];
int M,N;
char A[MAXN];
int DP[MAXN][MAXN];
int dp(int bas,int son)
{
	int &ret = DP[bas][son];
	if(ret != -1) return ret;
	if(bas >= son) return 0;
	ret = 500000000;
	if(A[bas] == A[son]) ret = dp(bas+1,son-1);
	ret = Min( ret , dp(bas+1,son) + C[A[bas]].f );
	ret = Min( ret , dp(bas,son-1) + C[A[son]].f );
	ret = Min( ret , dp(bas+1,son) + C[A[bas]].s );
	ret = Min( ret , dp(bas,son-1) + C[A[son]].s );
	return ret;
}
void solve()
{
	memset( DP , -1 , sizeof DP );
	int a,b,i;
	char c;
	scanf("%d %d",&M,&N);
	scanf("%s",A+1);
	FOR(i,1,M)
	{
		scanf(" %c %d %d",&c,&a,&b);
		C[c] = make_pair(a,b);
	}
	printf("%d\n" , dp(1,N) );
}
int main()
{
	solve();
	return 0;
}
