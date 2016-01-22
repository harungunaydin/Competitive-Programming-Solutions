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
int K,N;
int solve()
{
	K = read();
	N = read();
	int a,i,s(0);
	char c;
	FOR(i,1,N)
	{
		scanf("%d %c" , &a , &c );
		s += a;
		if(c == 'T')
		{
			if(s > 210) return K;
			if(++K == 9) K = 1;
		}
	}
	return K;
}
int main()
{
	printf("%d\n" , solve() );
	return 0;
}
