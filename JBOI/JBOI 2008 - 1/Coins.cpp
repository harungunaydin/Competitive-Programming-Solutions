#include <iostream>
#include <cstdio>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define MAXN 2000000
using namespace std;
int K,L,N;
int DP[MAXN+5][2];
int dp(int x,bool k)
{
	if(!x) return !k ? 2 : 1;
	if(DP[x][k]) return DP[x][k];
	int t1(2),t2(2);
	if(k)
	{
		t1 = dp(x-1,!k);
		if(x >= L)
			t2 = dp(x-L,!k);
		return DP[x][k] = (t1 == 1 || t2 == 1) ? 1 : 2;
	}
	else
	{
		t1 = dp(x-1,!k);
		if(x >= K)
			t2 = dp(x-K,!k);
		return DP[x][k] = (t1 == 1 || t2 == 1) ? 1 : 2;
	}
}
void solve()
{
	int a,i;
	char c;
	scanf("%d %d %d",&K,&L,&N);
	FOR(i,1,1000000)
		dp(i,0);
	FOR(i,1,N)
	{
		scanf("%d",&a);
		c = dp(a,0) == 1 ? 'A' : 'B';
		if(!c) { cout << "break\n"; break; }
		printf("%c",c);
	}
}
int main()
{
	solve();
	system("PAUSE");
	return 0;
}
