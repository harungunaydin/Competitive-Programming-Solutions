#include <iostream>
#include <algorithm>
#include <cstdio>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define TFOR(i,a,b) for(i=a; i>=b; i--)
#define MAX(a,b) ( (a) > (b) ? (a) : (b)  )
#define f first
#define s second
#define MAXN 50005
using namespace std;
typedef pair < int , int > pii;
pii A[MAXN];
int B[MAXN],H[2*MAXN],S[MAXN],T[MAXN];
void solve()
{
	int N,i,j,res(0),t;
	scanf("%d",&N);
	FOR(i,1,N)
		scanf("%d %d",&A[i].s,&A[i].f);
	sort(A+1,A+N+1);
	FOR(i,1,N)
	{
		S[i] += S[i-1] + !A[i].s;
		B[i] += B[i-1] + A[i].s;
		T[i] = S[i] - B[i];
	}
	FOR(i,1,N)
		H[T[i] + MAXN] = MAX( H[T[i]+MAXN] , i );
	FOR(i,1,N)
	{
		t = S[i-1] - B[i-1];
		if(H[t+MAXN] >= i)
			res = MAX( res , A[H[t+MAXN]].f - A[i].f );
	}
	printf("%d\n" , res );
}
int main()
{
	solve();
	return 0;
}
