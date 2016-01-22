#include <algorithm>
#include <cstdio>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define TFOR(i,a,b) for(i=a; i>=b; i--)
#define f first
#define s second
#define pb push_back
#define all(x) x.begin(),x.end()
#define MAXN 100005
using namespace std;
typedef pair < int , int > pii;
int read(){ int res(0),sign(1); char c;
	while(1){ c = getchar(); if('0' <= c && c <= '9') { res = c - '0'; break; } else if(c == '-') { sign = -1; break; } }
	while(1){ c = getchar(); if('0' <= c && c <= '9') res = res*10 + c - '0'; else break; }
	return res * sign;
}
int N;
int A[MAXN];
void solve()
{
	int i,res(0);
	N = read();
	FOR(i,1,N) A[i] = read();

	sort(A+1,A+N+1);

	FOR(i,1,N)
	{
		if(i < N - i + 1)
			res += A[N-i+1] - A[i];
		res += A[i];
	}

	printf("%d\n" , res );

}
int main()
{
	solve();
	return 0;
}
