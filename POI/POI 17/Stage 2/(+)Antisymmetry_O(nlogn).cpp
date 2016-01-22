#include <algorithm>
#include <cstdio>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define TFOR(i,a,b) for(i=a; i>=b; i--)
#define BASE 1009
#define all(x) x.begin(),x.end()
#define MAXN 500005
using namespace std;
typedef pair < int , int > pii;
int read(){ int res(0),sign(1); char c;
	while(1){ c = getchar(); if('0' <= c && c <= '9') { res = c - '0'; break; } else if(c == '-') { sign = -1; break; } }
	while(1){ c = getchar(); if('0' <= c && c <= '9') res = res*10 + c - '0'; else break; }
	return res * sign;
}
int H1[MAXN] , H2[MAXN] , us[MAXN];
char A[MAXN];
bool control(int k,int a)
{
	return H1[a] - H1[a-k] * us[k] == H2[a+1] - H2[a+k+1] * us[k];
}
int BS(int bas,int son,int x)
{
	if(bas == son) return bas;
	if(bas + 1 == son) return control(son,x) ? son : bas;
	int orta = ( bas + son ) >> 1;
	return control(orta,x) ? BS(orta,son,x) : BS(bas,orta-1,x);
}
void solve()
{
	int N,i;
	N = read();
	scanf("%s" , A+1 );
	us[0] = 1;
	FOR(i,1,N)
	{
		H1[i] = H1[i-1] * BASE + A[i];
		us[i] = us[i-1] * BASE;
	}
	TFOR(i,N,1)
		H2[i] = H2[i+1] * BASE + ( '0' + '1' - A[i] );

	long long res(0);

	FOR(i,1,N-1)
		res += BS(0, min( i , N-i ) , i);

	printf("%lld\n" , res );

}
int main()
{
	solve();
	return 0;
}
