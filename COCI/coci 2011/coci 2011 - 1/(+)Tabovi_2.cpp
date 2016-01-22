#include <iostream>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define all(x) x.begin(),x.end()
#define MAXN 1000
using namespace std;
int N;
int A[MAXN+5];
bool kontrol()
{
	int i;
	FOR(i,1,N)
		if(A[i])
			return 1;
	return 0;
}
void print()
{
	int i;
	FOR(i,1,N)
		printf("%d ",A[i]);
	printf("\n"); getchar(); getchar(); getchar();
}
void solve()
{
	int a,i,j,res(0),s(0);
	scanf("%d",&N);
	FOR(i,1,N)
		scanf("%d",A+i);
	FOR(i,1,N)
	{
		scanf("%d",&a);
		A[i]-=a;
	}
	while(kontrol())
	{
		a = 0;
		FOR(i,1,N+1)
		{
			if(A[i] > 0 && !a) a = i;
			if(a && A[i] <= 0)
			{
				res++;
				FOR(j,a,i-1)
					A[j]--;
				a = 0;
			}
		}
		a = 0;
		FOR(i,1,N+1)
		{
			if(A[i] < 0 && !a) a = i;
			if(a && A[i] >= 0)
			{
				res++;
				FOR(j,a,i-1)
					A[j]++;
				a = 0;
			}
		}
	}
	printf("%d\n",res);
}
int main()
{
	solve();
	return 0;
}

