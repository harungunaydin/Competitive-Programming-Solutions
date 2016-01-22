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
int N;
int A[MAXN];
bool control(int x)
{
	int i , t = A[x] + N;
	FOR(i,x,N)
		if(A[i] + N-i+1 > t)
			return false;
	return true;
}
int BS(int bas,int son)
{
	if(bas == son) return bas;
	if(bas + 1 == son) return control(bas) ? bas : son;
	int orta = ( bas + son ) >> 1;
	return control(orta) ? BS(bas,orta) : BS(orta+1,son);
}
void solve()
{
	int i;
	N = read();
	FOR(i,1,N)
		A[i] = read();

	sort(A+1,A+N+1);

	printf("%d\n" , N - BS(1,N) + 1 );

}
int main()
{
	solve();
	return 0;
}
