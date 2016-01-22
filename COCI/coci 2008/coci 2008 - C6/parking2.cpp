#include <iostream>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define all(x) x.begin(),x.end()
#define MAXN 1000
using namespace std;
int D[MAXN+5],E[5];
void solve()
{
	int A,B,C,a,b,c,i,j,res(0);
	scanf("%d %d %d",E+1,E+2,E+3);
	FOR(i,1,3)
	{
		scanf("%d %d",&a,&b);
		FOR(j,a,b-1)
			D[j]++;
	}
	FOR(i,1,100)
		res+=E[D[i]]*D[i];
	printf("%d\n",res);
}
int main()
{
	solve();
	return 0;
}
