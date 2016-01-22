#include <iostream>
#include <cstdio>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define MAXN 150
using namespace std;
long long A,B,S,res(-1);
long long us10[20];
long long DP[MAXN+5][20];
long long dp(long long bas,long long t,long long sayi)
{
	if(t > S || sayi+us10[bas]-1 < A || sayi > B) return 0;
	if(!bas) { if(t == S && res == -1) res = sayi; return t == S; }
	long long i,s(0);
	bool flag = (sayi >= A && sayi+us10[bas]-1 <= B);
	if(flag && DP[t][bas] != -1) return DP[t][bas];
	FOR2(i,10)
		s+=dp(bas-1,t+i,sayi+i*us10[bas-1]);
	return flag ? DP[t][bas] = s : s;
}
void solve()
{
	scanf("%lld %lld %lld",&A,&B,&S);
	long long i,j;
	us10[0] = 1;
	FOR(i,1,17)
		us10[i] = us10[i-1]*10;
	FOR(i,0,MAXN+2)
		FOR(j,0,19)
			DP[i][j] = -1;
	printf("%lld\n",dp(16,0,0));
	printf("%lld\n",res);
}
int main()
{
	solve();
	return 0;
}
