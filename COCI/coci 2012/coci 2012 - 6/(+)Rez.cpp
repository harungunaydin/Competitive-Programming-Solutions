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
	int K = read() , a(2) , i , s(1);

	while(a < K) a += ++s;

	if(K == 1) s = 0;

	printf("%d\n" , s );

	FOR(i,1,s)
		printf("%d %d %d %d\n" , 5000 - i , -5000 , -5000 , i - 5000 );

}
int main()
{
	solve();
	return 0;
}
