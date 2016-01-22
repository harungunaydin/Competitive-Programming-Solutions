#include <algorithm>
#include <cstdio>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define TFOR(i,a,b) for(i=a; i>=b; i--)
#define all(x) x.begin(),x.end()
#define MAXN 
using namespace std;
int read()
{
	int res(0),sign(1);
	char c;
	while(1)
	{
		c = getchar();
		if('0' <= c && c <= '9') { res = c - '0'; break; }
		else if(c == '-') { sign = -1; break; }
	}
	while(1)
	{
		c = getchar();
		if('0' <= c && c <= '9') res = res*10 + c - '0';
		else break;
	}
	return res * sign;
}
void solve()
{
	int a,i,s(0),t(1);
	a = read();

	while(t < a) t <<= 1;

	printf("%d " , t );

	for(; t ; t >>= 1,s++)
	{
		while( a >= t )
			a -= t;
		if(!a) break;
	}

	printf("%d\n" , s );

}
int main()
{
	solve();
	return 0;
}
