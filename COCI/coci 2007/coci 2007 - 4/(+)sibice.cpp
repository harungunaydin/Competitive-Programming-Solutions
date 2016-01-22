#include <cstdio>
#define FOR(i,a,b) for(i=a; i<=b; i++)
void solve()
{
	int H,N,W,a;
	scanf("%d %d %d",&N,&H,&W);
	W = W * W + H * H;
	while(N--)
	{
		scanf("%d",&a);
		if(a * a <= W) printf("DA\n");
		else printf("NE\n");
	}
}
int main()
{
	solve();
	return 0;
}
