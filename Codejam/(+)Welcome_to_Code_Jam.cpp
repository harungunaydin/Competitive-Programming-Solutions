#include <iostream>
#include <cstdio>
#include <cstring>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define TFOR(i,a,b) for(i=a; i>=b; i--)
#define MOD 10000
#define MAXN 600
using namespace std;
FILE *in,*out;
string str,str2;
int M,N;
int DP[MAXN][MAXN];
char A[MAXN];
int dp(int x,int k)
{
	int &ret = DP[x][k];
	if(ret != -1) return ret;
	if(k == M) return ret = 1;
	if(x == N) return ret = 0;
	if(str[x] == str2[k])
		return ret = ( dp(x+1,k+1) + dp(x+1,k) ) % MOD ;
	return ret = dp(x+1,k);
}
int main()
{
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
	str2 = "welcome to code jam";
	M = str2.size();
	int T,i,j;
	scanf("%d",&T);
	getline(cin,str);
	FOR(i,1,T)
	{
		memset( DP , -1 , sizeof DP );
		memset( A , 0 , sizeof A );
		gets(A);
		str.clear();
		str = A;
		N = str.size();
		int a,s(0),t = dp(0,0);
		a = t;
		if(!a) s = 1;
		while(a) { a /= 10; s++; }
		printf("Case #%d: ",i);
		
		FOR(j,1,4-s)
			printf("0");
		
		printf("%d\n",t);
	}
	return 0;
}
