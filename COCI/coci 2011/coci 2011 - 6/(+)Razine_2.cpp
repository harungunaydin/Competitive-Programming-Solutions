#include <iostream>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define TFOR(i,a,b) for(i=a; i>=b; i--)
#define all(x) x.begin(),x.end()
#define MAXN 
using namespace std;
int A[MAXN+5];
void solve()
{
	int N,i,res(0);
	scanf("%d",&N);
	FOR(i,1,N)
		scanf("%d",A+i);
	TFOR(i,N-1,1)
		if(A[i] >= A[i+1])
		{
			res+=A[i]-A[i+1]+1;
			A[i] = A[i+1] - 1;
		}
	printf("%d\n",res);
}
int main()
{
	solve();
	return 0;
}
