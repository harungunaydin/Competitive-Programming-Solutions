#include <algorithm>
#include <cstdio>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define TFOR(i,a,b) for(i=a; i>=b; i--)
#define all(x) x.begin(),x.end()
#define MAXN 300005
using namespace std;
int N;
int A[MAXN];
void solve()
{
	int i,k;
	scanf("%d",&N);
	FOR(i,1,N)
		scanf("%d",A+i);
	k = N;
	TFOR(i,N,1)
		if(A[i] == k)
			k--;
	printf("%d\n" , k );
}
int main()
{
	solve();
	return 0;
}
