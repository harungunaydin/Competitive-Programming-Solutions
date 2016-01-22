#include <iostream>
#include <cstdio>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define OO 20000000000000ll
#define MAXN 10000
using namespace std;
int N;
int A[MAXN+5],B[MAXN+5],D[MAXN+5];
void solve()
{
	int i,j,s;
	long long res(OO),t;
	scanf("%d",&N);
	FOR(i,1,N) scanf( "%lld %lld" , B+i , D+i );
	FOR(i,1,N)
	{
		s = t = 0;
		j = (i == N) ? 1 : i + 1;
		for(; j != i ; j++)
		{
			s+=D[(j == 1) ? N : j-1];
			A[j] = s;
			if(j == N) j = 0;
		}
		s = 0;
		j = (i == 1) ? N : i - 1;
		for(; j != i; j--)
		{
			s+=D[j];
			if(s < A[j]) A[j] = s;
			t+=A[j] * B[j];
			if(j == 1) j = N + 1;
		}
		if(t < res) res = t;
	}
	printf("%lld\n",res);
}
int main()
{
	solve();
	return 0;
}
