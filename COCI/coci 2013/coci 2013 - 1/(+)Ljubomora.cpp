#include <algorithm>
#include <cstdio>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define TFOR(i,a,b) for(i=a; i>=b; i--)
#define f first
#define s second
#define pb push_back
#define all(x) x.begin(),x.end()
#define MAXN 300005
using namespace std;
typedef pair < int , int > pii;
int read(){ int res(0),sign(1); char c;
	while(1){ c = getchar(); if('0' <= c && c <= '9') { res = c - '0'; break; } else if(c == '-') { sign = -1; break; } }
	while(1){ c = getchar(); if('0' <= c && c <= '9') res = res*10 + c - '0'; else break; }
	return res * sign;
}
int M,N;
long long A[MAXN];
bool control(long long x)
{
	long long res(0);
	int i;

	FOR(i,1,M)
	{
		res += ( (A[i]+x-1) / x);
		if(res > N) return false;
	}
	return true;
}
long long BS(long long bas,long long son)
{
	if(bas == son) return bas;
	if(bas + 1 == son) return control(bas) ? bas : son;
	long long orta = ( bas + son ) >> 1;
	return control(orta) ? BS(bas,orta) : BS(orta+1,son);
}
void solve()
{
	int i;
	N = read(); M = read();
	FOR(i,1,M)
		A[i] = read();

	printf("%lld\n" , BS(1,100000000000000ll) );

}
int main()
{
	solve();
	return 0;
}
