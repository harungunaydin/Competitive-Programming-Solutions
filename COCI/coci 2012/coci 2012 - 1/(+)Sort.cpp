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
int N;
long long F[MAXN];
int A[MAXN];
void solve()
{
	int i,j,k(1);
	N = read();
	FOR(i,1,N)
		A[i] = read();
	A[N+1] = 1000000000;

	long long res(0);
	FOR(i,2,N+1)
		if(A[i] > A[i-1])
		{
			reverse(A+k,A+i);
			k = i;
			res++;
		}

	FOR(i,1,N)
	{
		for(j = A[i]; j <= N; j += j&-j) res += F[j];
		for(j = A[i]; j ; j -= j&-j) F[j]++;
	}

	printf("%lld\n" , res );

}
int main()
{
	solve();
	return 0;
}
