#include <algorithm>
#include <cstdio>
#include <cstring>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define TFOR(i,a,b) for(i=a; i>=b; i--)
#define all(x) x.begin(),x.end()
#define MAXN 2005
#define MAXQ 150005
using namespace std;
int M,N,Q;
int A[MAXN] , B[MAXN] , DP[MAXQ];
int solve()
{
	int a,i,j,res(0),sum(0),t;
	scanf("%d %d %d",&Q,&N,&M);
	FOR(i,1,N)
	{
		scanf("%d",A+i);
		sum += A[i];
	}
	DP[0] = true;
	FOR(i,1,N)
		TFOR(j,Q,A[i])
			if(DP[j-A[i]])
				DP[j] = true;

	TFOR(i,Q,0)
		if(DP[i])
			break;

	t = i;
	
	Q -= t;
	res += t;

	if(!Q) return res;

	if(t < sum) return res + Q - 1;

	FOR(i,1,M)
		scanf("%d",B+i);

	sort(B+1,B+M+1);
	TFOR(i,M,1)
	{
		if(Q >= B[i])
		{
			Q -= B[i];
			res += B[i] - 1;
		}
		else
			return res + Q - 1;
	}
	return res;

}
int main()
{
	printf("%d\n" , solve() );
	return 0;
}
