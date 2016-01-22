#include <algorithm>
#include <cstdio>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define TFOR(i,a,b) for(i=a; i>=b; i--)
#define all(x) x.begin(),x.end()
#define MAXN 10
using namespace std;
int A[MAXN];
void solve()
{
	int a,b,c,d,e,f,g;
	FOR(a,1,9)
		scanf("%d",A+a);

	FOR(a,1,9)
		FOR(b,a+1,9)
			FOR(c,b+1,9)
				FOR(d,c+1,9)
					FOR(e,d+1,9)
						FOR(f,e+1,9)
							FOR(g,f+1,9)
								if(A[a] + A[b] + A[c] + A[d] + A[e] + A[f] + A[g] == 100)
								{
									printf("%d\n%d\n%d\n%d\n%d\n%d\n%d\n" , A[a] , A[b] , A[c] , A[d] , A[e] , A[f] , A[g] );
									return;
								}

}
int main()
{
	solve();
	return 0;
}
