#include <cstdio>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define TFOR(i,a,b) for(i=a; i>=b; i--)
#define MAXK 100001
#define MAXN 101
using namespace std;
int K,N;
int A[MAXN];
short B[MAXN] , DP2[MAXK];
bool DP[MAXK];
void solve()
{
	short *q;
	int a,b,t,s , *p;
	int i,j;
	scanf("%d %d",&N,&K);

	FOR(i,1,N) scanf("%d",A+i);

	FOR(i,1,N) scanf("%hd",B+i);

	p = A + 1;
	q = B + 1;
	FOR(i,1,N)
	{
		a = *p;
		b = *q;
		p++;
		q++;
		s = a - 1;

		FOR(j,0,s) DP2[j] = 0;
		
		FOR(j,a,K)
			if(!DP[j] && DP[j-a] && (t = DP2[j-a] + 1) <= b)
			{
				DP[j] = true;
				DP2[j] = t;
			}
			else
				DP2[j] = false;
	}
	t = 0;
	FOR(i,1,K)
		if(DP[i])
		{
			DP[i] = false;
			t++;
		}
	printf("%d\n" , t );
}
int main()
{
	DP[0] = true;
	int T,i;
	scanf("%d",&T);
	FOR(i,1,T)
	{
		printf("Case %d: ",i);
		solve();
	}
	return 0;
}
