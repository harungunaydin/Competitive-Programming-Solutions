#include <iostream>
#include <cstdio>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define MAXN 100001
using namespace std;
typedef pair < int , int > pii;
inline int Abs( int a ) { return a > 0 ? a : -a; }
inline int Min( int a , int b ) { return a < b ? a : b; }
inline int Max( int a , int b ) { return a > b ? a : b; }
int A[MAXN];
void solve()
{
	int K,N,a,i,j,s(0);
	scanf("%d %d",&N,&K);
	FOR(i,1,K)
	{
		scanf("%d",&a);
		FOR(j,1,a) A[++s] = i;
	}
	FOR(i,1,N/2)
		printf("%d %d\n",A[i],A[i+N/2]);
}
int main()
{
	solve();
	return 0;
}
