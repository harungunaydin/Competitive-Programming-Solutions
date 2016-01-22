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
	int N = read(),i,res(123123123);

	FOR(i,0,N/3)
		if(!((N-3*i)%5))
			res = min( res , i + (N-3*i) / 5 );

	if(res > N) res = -1;

	printf("%d\n" , res );

}
int main()
{
	solve();
	return 0;
}
