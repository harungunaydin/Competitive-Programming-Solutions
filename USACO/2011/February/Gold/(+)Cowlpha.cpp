#include <iostream>
#include <cstdio>
#include <cstring>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define TFOR(i,a,b) for(i=a; i>=b; i--)
#define F(x) ( (x < 26) ? x + 'A' : x - 26 + 'a' )
#define MAXN 251
#define MOD 97654321
using namespace std;
int U,L,P;
int DP[MAXN][MAXN][52];
bool C[300][300];
int dp(int b,int k,int a)
{
	if(b > U || k > L) return 0;
	int &ret = DP[b][k][a];
	if(ret != -1) return ret;
	if(b == U && k == L) return ret = 1;
	ret = 0;
	int i;
	char c = F(a);
	bool f = (!b && !k);
	FOR2(i,26)
		if(f || C[c][F(i)])
			ret = ( ret + dp(b+1,k,i) ) % MOD;
	FOR(i,26,51)
		if(f || C[c][F(i)])
			ret = ( ret + dp(b,k+1,i) ) % MOD;
	return ret;
}
void solve()
{
	memset( DP , -1 , sizeof DP );
	string str;
	int i;
	scanf("%d %d %d",&U,&L,&P);
	FOR(i,1,P)
	{
		cin >> str;
		C[str[0]][str[1]] = true;
	}
	printf("%d\n" , dp(0,0,0) );
}
int main()
{
	solve();
	return 0;
}
