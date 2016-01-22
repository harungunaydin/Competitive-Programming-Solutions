#include <iostream>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define MAXN 5
using namespace std;
int A[MAXN+5];
void solve()
{
	int i,j;
	FOR(i,1,5)
		scanf("%d",A+i);
	while(A[1] != 1 || A[2] != 2 || A[3] != 3 || A[4] != 4 || A[5] != 5)
	{
		FOR(i,1,4)
			if(A[i] > A[i+1])
			{
				swap(A[i],A[i+1]);
				FOR(j,1,5)
				{
					printf("%d",A[j]);
					if(j < 5) printf(" ");
				}
				printf("\n");
			}
	}
}
int main()
{
	solve();
	return 0;
}
