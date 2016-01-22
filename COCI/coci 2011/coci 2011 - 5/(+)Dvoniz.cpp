#include <algorithm>
#include <cstdio>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define TFOR(i,a,b) for(i=a; i>=b; i--)
#define H(a,b) ( T[b] - T[a-1] )
#define control(a,k) ( H(a,a+k-1) <= S && H(a+k,a+2*k-1) <= S )
#define all(x) x.begin(),x.end()
#define MAXN 100005
using namespace std;
long long S;
long long A[MAXN] , T[MAXN];
int N;
int BS(int bas,int son,int a)
{
	if(bas > son) return 0;
	if(bas == son) return control(a,bas) ? bas : 0;
	if(bas + 1 == son) return control(a,son) ? son : control(a,bas) ? bas : 0;
	
	register int orta = ( bas + son ) >> 1;

	if(H(a,a+orta-1) > S) return BS(bas,orta-1,a);

	if(control(a,orta)) return max( orta , BS(orta+1,son,a) );

	register int t = BS(orta+1,son,a);

	if(t) return t;

	return BS(bas,orta-1,a);

}
void solve()
{
	register int i;
	scanf("%d %lld",&N,&S);
	FOR(i,1,N)
	{
		scanf("%lld" , A+i );
		T[i] = T[i-1] + A[i];
	}

	FOR(i,1,N)
		printf("%d\n" , BS(1 , (N-i+1)/2 , i ) * 2 );

}
int main()
{
	solve();
	return 0;
}
