#include <algorithm>
#include <cstdio>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define TFOR(i,a,b) for(i=a; i>=b; i--)
#define all(x) x.begin(),x.end()
#define MAXN 
using namespace std;
void yaz(int t)
{
	int a = t / 3600;
	t -= a * 3600;

	int b = t / 60;

	int c = t % 60;

	printf("%d%d:%d%d:%d%d\n" , a/10 , a%10 , b/10 , b%10 , c/10 , c%10 );
}
void solve()
{
	int a1,a2,b1,b2,c1,c2;
	scanf("%d:%d:%d" , &a1 , &b1 , &c1 );
	scanf("%d:%d:%d" , &a2 , &b2 , &c2 );

	int t1 = a1 * 3600 + b1 * 60 + c1;

	int t2 = a2 * 3600 + b2 * 60 + c2;

	if(t2 > t1) yaz(t2-t1);
	else yaz( 24*3600 - (t1 - t2) );

}
int main()
{
	solve();
	return 0;
}
