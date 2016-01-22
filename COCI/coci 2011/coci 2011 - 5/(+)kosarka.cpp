#include <algorithm>
#include <cstdio>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define TFOR(i,a,b) for(i=a; i>=b; i--)
using namespace std;
int A[50][65][3];
void yazdir(int x)
{
	int a = x / 60;
	int b = x % 60;

	printf("%d%d:",a/10,a%10);
	printf("%d%d\n",b/10,b%10);

}
void solve()
{
	int N,a,b,i,j,k;
	scanf("%d",&N);
	FOR(i,1,N)
	{
		scanf("%d %d:%d",&k,&a,&b);
		A[a][b][k]++;
	}

	int res1(0) , res2(0) , s1(0),s2(0) ;

	FOR(i,0,47)
		FOR(j,0,59)
		{
			s1 += A[i][j][1];
			s2 += A[i][j][2];
			if(s1 > s2) res1++;
			if(s2 > s1) res2++;
		}

	yazdir(res1);
	yazdir(res2);

}
int main()
{
	solve();
	return 0;
}
