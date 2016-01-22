#include <iostream>
#include <cmath>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define all(x) x.begin(),x.end()
#define MAXN 
using namespace std;
void solve()
{
	int B,M,N,R,a,b;
	scanf("%d %d",&R,&B);
	a = (R+4)/2;
	b = a; // b = M + N
	a = (int)sqrt(a*a-4*(B+R)); // a = M - N
	M = (a+b)/2;
	N = (B+R)/M;
	printf("%d %d\n",max(M,N),min(M,N));
}
int main()
{
	solve();
	return 0;
}
