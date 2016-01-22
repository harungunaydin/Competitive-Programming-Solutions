#include <algorithm>
#include <cstdio>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define TFOR(i,a,b) for(i=a; i>=b; i--)
#define all(x) x.begin(),x.end()
#define MAXN 5005
using namespace std;
int N;
int A[MAXN];
bool hash[MAXN];
void solve()
{
	int i,j,res(0),t;
	scanf("%d",&N);
	FOR(i,1,N)
		scanf("%d" , A+i);

	FOR(i,2,N)
		if(!hash[i])
		{
			res++;
			t = A[i] - 1;
			FOR(j,i+1,N)
				if( !((A[j] - 1)%t) )
					hash[j] = true;
		}

	printf("%d\n" , res );

}
int main()
{
	solve();
	return 0;
}
