#include <iostream>
#include <cstdio>
#include <cstdlib>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define TFOR(i,a,b) for(i=a; i>=b; i--)
#define MAXN 1000
using namespace std;
int K,L,M,N,s;
int A[MAXN+5];
inline bool control(int x)
{
	int i;
	if(x < L) return 1;
	TFOR(i,x-1,x-L+1)
		if(A[i] != A[x])
			return 1;
	return 0;
}
void rec(int x)
{
	if(x == M + 1) { s++; return; }
	A[x] = 0;
	if(control(x)) rec(x+1);
	A[x] = 1;
	if(control(x)) rec(x+1);
}
void solve()
{
	scanf("%d %d %d %d",&K,&N,&M,&L);
	rec(1);
	int k(0);
	while(s)
	{
		k++;
		s >>= 1;
	}
	srand(time(NULL));
	printf("%d\n",(N/M) * ( k - 1 ) + rand()%2 + 1);
}
int main()
{
	solve();
	return 0;
}
