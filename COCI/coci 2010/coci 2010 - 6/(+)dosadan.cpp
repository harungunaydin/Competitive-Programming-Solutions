#include <cstdio>
using namespace std;
void solve()
{
	int N,a,i,k,res;
	scanf("%d",&N);
	while(N--)
	{
		scanf("%x",&a);
		int t1 = a ^ '.';
		int t2 = a ^ ' ';
		if( '0' <= t1 && t1 <= '9' )
			printf(".");
		else if( '0' <= t2 && t2 <= '9' )
			printf(".");
		else
			printf("-");
	}
	printf("\n");
}
int main()
{
	solve();
	return 0;
}
