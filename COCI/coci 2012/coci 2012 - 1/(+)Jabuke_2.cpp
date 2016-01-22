#include <iostream>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define all(x) x.begin(),x.end()
#define MAXN 
using namespace std;
void solve()
{
	int K,M,N,a,b,c,i,k,res(0);
	scanf("%d %d %d",&N,&M,&K);
	a = 1; b = M;
	FOR2(i,K)
	{
		scanf("%d",&c);
		if(c > b) { res+=c-b; a+=c-b; b = c; }
		else if(c < a) { res+=a-c;  b-=a-c; a = c; }
	}
	printf("%d\n",res);
}
int main()
{
	solve();
	return 0;
}
