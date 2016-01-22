#include <iostream>
#include <cstdio>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define TFOR(i,a,b) for(i=a; i>=b; i--)
#define MAXN 100005
using namespace std;
typedef pair < int , int > pii;
int K,M,N;
int A[MAXN];
bool H[MAXN];
void solve()
{
	int a,i,j,res(0);
	scanf("%d %d %d",&N,&M,&K);
	FOR(i,1,N) scanf("%d",A+i);
	FOR(i,1,M)
	{
		scanf("%d",&a);
		H[a] = true;
		j = a;
		while(A[j-1] >= A[j] && !H[j-1]) H[--j] = true;
		j = a;
		while(A[j+1] >= A[j] && !H[j+1]) H[++j] = true;
	}
	FOR(i,1,K)
	{
		scanf("%d",&a);
		res += H[a];
	}
	printf("%d\n" , res );
}
int main()
{
	solve();
	return 0;
}
