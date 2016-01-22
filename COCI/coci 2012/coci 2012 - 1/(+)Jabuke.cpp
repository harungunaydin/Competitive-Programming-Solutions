#include <algorithm>
#include <cstdio>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define TFOR(i,a,b) for(i=a; i>=b; i--)
#define f first
#define s second
#define pb push_back
#define all(x) x.begin(),x.end()
#define MAXN 
using namespace std;
typedef pair < int , int > pii;
int read(){ int res(0),sign(1); char c;
	while(1){ c = getchar(); if('0' <= c && c <= '9') { res = c - '0'; break; } else if(c == '-') { sign = -1; break; } }
	while(1){ c = getchar(); if('0' <= c && c <= '9') res = res*10 + c - '0'; else break; }
	return res * sign;
}
void solve()
{
	int K,M,N,a,f,res(0),s;
	N = read(); M = read();
	K = read();

	f = 1; s = M;

	while(K--)
	{
		scanf("%d",&a);
		if(a > s)
		{
			res += a - s;
			f += a - s;
			s += a - s;
		}
		else if(a < f)
		{
			res += f - a;
			s -= f - a;
			f -= f - a;
		}
	}
	printf("%d\n" , res );
}
int main()
{
	solve();
	return 0;
}
