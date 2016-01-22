#include <iostream>
#include <cstdio>
#include <cstring>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define INF 2000000000ll
#define MAXN 201
using namespace std;
inline long long Min(long long a,long long b) { return a < b ? a : b; }
int K,M,N,baslangic,hedef;
int H[1001],T[22];
long long DP[MAXN][22],TMP[MAXN][MAXN];
long long A[MAXN][MAXN][22];
long long dp(int x,int k)
{
	long long &ret = DP[x][k];
	if(ret != -1) return ret;
	if(!k) return x == hedef ? 0 : INF;
	ret = INF;
	int i;
	FOR(i,1,N)
		ret = Min( ret , A[x][i][T[k]] + dp(i,k-1) );
	return ret;
}
void solve()
{
	memset( DP , -1 , sizeof DP );
	int a,b,c,i,j,k,s;
	FOR(i,1,200) FOR(j,1,200) A[i][j][0] = INF;
	scanf("%d %d %d %d",&K,&M,&baslangic,&hedef);
	FOR(i,1,M)
	{
		scanf("%d %d %d",&c,&a,&b);
		if(!H[a]) H[a] = ++N;
		if(!H[b]) H[b] = ++N;
		A[H[a]][H[b]][0] = A[H[b]][H[a]][0] = c;
	}
	FOR(a,1,20)
	{
		memset( TMP , 127 , sizeof TMP );
		FOR(k,1,N)
			FOR(i,1,N)
				FOR(j,1,N)
					TMP[i][j] = Min( TMP[i][j] , A[i][k][a-1] + A[k][j][a-1] );
		FOR(i,1,N)
			FOR(j,1,N)
				A[i][j][a] = TMP[i][j];
	}
	a = K;
	b = s = 0;
	while(a)
	{
		if(a&1) T[++s] = b;
		b++;
		a >>= 1;
	}
	baslangic = H[baslangic];
	hedef = H[hedef];
	printf("%lld\n" , dp(baslangic,s) );
}
int main()
{
	solve();
	return 0;
}
