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
long long A[1500];
int f(long long x)
{
	int mask(0);
	while(x)
	{
		mask |= (1<<(x%10));
		x /= 10;
	}
	return mask;
}
void solve()
{
	long long a,res(0);
	int i,j;
	N = read();
	FOR(i,1,N)
	{
		scanf("%lld",&a);
		A[f(a)]++;
	}
	FOR(i,0,1023)
		FOR(j,i,1023)
			if(i&j)
			{
				if(i == j) res += ( A[i] * (A[i] - 1) ) / 2;
				else res += A[i] * A[j];
			}

	printf("%lld\n" , res );

}
int main()
{
	solve();
	return 0;
}
