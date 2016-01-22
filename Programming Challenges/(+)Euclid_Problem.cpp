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
int Ex_gcd(int a,int b,int &x,int &y)
{
	if(!b) { x = 1; y = 0; return a; }
	int x1,y1;
	int t = Ex_gcd(b,a%b,x1,y1);
	x = y1;
	y = x1 - (a/b)*y1;
	return t;
}
void solve()
{
	int a,b,gcd,x,y;
	while(scanf("%d %d",&a,&b) != -1)
	{
		gcd = Ex_gcd(a,b,x,y);
		printf("%d %d %d\n" , x , y , gcd );
	}
}
int main()
{
	solve();
	return 0;
}
