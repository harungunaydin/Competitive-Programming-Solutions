#include <algorithm>
#include <cstdio>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define TFOR(i,a,b) for(i=a; i>=b; i--)
#define f first
#define s second
#define pb push_back
#define all(x) x.begin(),x.end()
#define MAXN 1000005
using namespace std;
typedef pair < int , int > pii;
int read(){ int res(0),sign(1); char c;
	while(1){ c = getchar(); if('0' <= c && c <= '9') { res = c - '0'; break; } else if(c == '-') { sign = -1; break; } }
	while(1){ c = getchar(); if('0' <= c && c <= '9') res = res*10 + c - '0'; else break; }
	return res * sign;
}
long long M;
int N;
long long A[MAXN];
bool control(long long k)
{
	long long t(0);
	int i;
	FOR(i,1,N)
		if(A[i] > k)
			t += (long long) A[i] - k;
	return t >= M;
}
int BS(int bas,int son)
{
	if(bas == son) return bas;
	if(bas + 1 == son) return control(son) ? son : bas;
	int orta = ( bas + son ) >> 1;
	return control(orta) ? BS(orta,son) : BS(bas,orta-1);
}
void solve()
{
	long long maxi(0);
	int i;
	N = read(); M = read();

	FOR(i,1,N)
	{
		A[i] = read();
		maxi = max( maxi , A[i] );
	}

	printf("%d\n" , BS(0,maxi) );

}
int main()
{
	solve();
	return 0;
}
