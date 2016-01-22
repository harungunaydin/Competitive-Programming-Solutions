#include <iostream>
#include <cstdio>
#include <cstring>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define MOD 100000000
#define MAXN 2002
using namespace std;
inline int Abs( int a ) { return a > 0 ? a : -a; }
int D,K,N,bir,sifir;
char A[MAXN];
int B[MAXN],S[MAXN];
int DP[MAXN][MAXN];
inline int dp(int x,int b)
{
	int &ret = DP[x][b];
	if(ret != -1) return ret;
	int k,s = x - 1 - b;
	if(x == N + 1) return ret = (b == bir && s == sifir);
	ret = 0;
	if(s < sifir && Abs(S[s+1] - x) <= D) ret += dp(x+1,b);
	if(b < bir && Abs(B[b+1] - x) <= D) ret += dp(x+1,b+1);
	return ret = (ret >= MOD) ? (ret % MOD) + MOD : ret;
}
void solve()
{
	memset( DP , -1 , sizeof DP );
	int i,b(0),s(0);
	scanf("%d %d %d",&N,&D,&K);
	FOR(i,1,N)
	{
		scanf(" %c",A+i);
		if(A[i] == '0') S[++sifir] = i;
		else B[++bir] = i;
	}
	printf("%d\n" , dp(1,0) % MOD );
	FOR(i,1,N)
	{
		if(dp(i+1,b) >= K && Abs(S[s+1] - i) <= D) { s++; printf("0"); }
		else { if(Abs(S[s+1] - i) <= D) K -= dp(i+1,b); b++; printf("1"); }
	}
}
int main()
{
	solve();
	return 0;
}
