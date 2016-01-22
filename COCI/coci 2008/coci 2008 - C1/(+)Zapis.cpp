#include <iostream>
#include <cmath>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define MOD 100000
#define MAXN 200
using namespace std;
int N;
long long DP[MAXN+5][MAXN+5];
char A[MAXN+5];
bool flag;
long long hesapla(char a,char b)
{
	if(a == ')' || a == '}' || a == ']' || b == '(' || b == '{' || b == '[') return 0;
	if(a == '?' && b == '?') return 3;
	if(a == '?' || b == '?') return 1;
	if(a == '(' && b == ')') return 1;
	if(a == '{' && b == '}') return 1;
	if(a == '[' && b == ']') return 1;
	return 0;
}
long long TP(int bas,int son)
{
	if(DP[bas][son] != -1) return DP[bas][son];
	if(bas>son) return 1;
	long long a,i,t(0);
	for(i=bas+1; i<=son; i+=2)
	{
		a = hesapla(A[bas],A[i]);
		if(a)
			t+=a*(TP(bas+1,i-1)%MOD)*(TP(i+1,son)%MOD);
	}
	if(t > MOD) { flag = true; t%=MOD; }
	return DP[bas][son] = t;
}
void solve()
{
	int b,i,j;
	long long a;
	scanf("%d",&N);
	FOR(i,1,N)
		scanf(" %c",A+i);
	FOR(i,0,N+1)
		FOR(j,0,N+1)
			DP[i][j] = -1;
	a = TP(1,N);
	b = (int) log10(a) + 1;
	if(flag)
		FOR2(i,5-b)
			printf("0");
	printf("%lld\n",a);
}
int main()
{
	solve();
	return 0;
}
