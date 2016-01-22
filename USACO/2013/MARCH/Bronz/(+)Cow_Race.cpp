#include <iostream>
#include <cstdio>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define MAXN 1000001
using namespace std;
int M,N;
int A[MAXN],B[MAXN];
void solve()
{
	int a,b,i,j,res(0),t(0),x(0);
	scanf("%d %d",&N,&M);
	FOR(i,1,N)
	{
		scanf("%d %d",&a,&b);
		for(j = t + 1; j <= t + b; j++)
		{
			x += a;
			A[j] = x;
		}
		t += b;
	}
	t = x = 0;
	FOR(i,1,M)
	{
		scanf("%d %d",&a,&b);
		for(j = t + 1; j <= t + b; j++)
		{
			x += a;
			B[j] = x;
		}
		t += b;
	}
	FOR(i,2,t)
		res += ( (A[i] > B[i] && A[i-1] <= B[i-1]) || (A[i] < B[i] && A[i-1] >= B[i-1]) );
	printf("%d\n" , res );
}
int main()
{
	freopen("cowrace.in","r",stdin);
	freopen("cowrace.out","w",stdout);
	solve();
	return 0;
}
