#include <iostream>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define all(x) x.begin(),x.end()
#define MAXN 
using namespace std;
void solve()
{
	int A,B,V;
	scanf("%d %d %d",&A,&B,&V);
	if((V-A)%(A-B) == 0)
		printf("%d\n",(V-A)/(A-B) + 1);
	else
		printf("%d\n",(V-A)/(A-B) + 2);
}
int main()
{
	solve();
	return 0;
}
