#include <iostream>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define f first
#define s second
using namespace std;
typedef pair<int,int> pii;
pii p[1000005];
int M,N;
int A[30][30];
bool hash[30][30];
pii maxibul()
{
	int i,j,maxi=0;
	pii result;
	FOR(i,1,M)
		FOR(j,1,N)
			if(A[i][j] > maxi)
			{
				maxi=A[i][j];
				result.f=i;
				result.s=j;
			}
}
void solve()
{
	int i,j;
	scanf("%d %d",&M,&N);
	FOR(i,1,M)
		FOR(j,1,N)
			scanf("%d",&A[i][j]);
	
}
int main()
{
	solve();
	system("PAUSE");
	return 0;
}
