#include <iostream>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define all(x) x.begin(),x.end()
#define MAXN 
using namespace std;
int solve()
{
	int a,b,c;
	scanf("%d %d %d",&a,&b,&c);
	if(a > b) swap(a,b);
	if(a > c) swap(a,c);
	if(b > c) swap(b,c);
	return (b - a == c - b) ? b + c - a : a + c - b;
}
int main()
{
	printf("%d\n",solve());
	return 0;
}
