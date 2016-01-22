#include <algorithm>
#include <cstdio>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define TFOR(i,a,b) for(i=a; i>=b; i--)
#define all(x) x.begin(),x.end()
#define MAXN 55
using namespace std;
char A[MAXN];
void solve()
{
	scanf("%s" , A );

	int a(1),b(2),c(3),i;
	for(i = 0; A[i]; i++)
		if(A[i] == 'A')
			swap(a,b);
		else if(A[i] == 'B')
			swap(b,c);
		else
			swap(a,c);

	if(a == 1) printf("1\n");
	if(b == 1) printf("2\n");
	if(c == 1) printf("3\n");

}
int main()
{
	solve();
	return 0;
}
