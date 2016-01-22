#include <iostream>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define all(x) x.begin(),x.end()
#define MAXN 10000
using namespace std;
int C[MAXN+5],RES[MAXN+5],T[MAXN+5];
void solve()
{
	int N,a,c(0),cs(0),i,t(0),ts(0);
	scanf("%d",&N);
	fill(T,T+N+1,1);
	FOR(i,1,N)
	{
		scanf("%d",&a);
		if(a%3)
			C[++cs] = a;
		else
			T[++ts] = a;
	}
	FOR(i,1,N)
	{
		if(i&1)
		{
			if(t < ts)
				RES[i] = T[++t];
			else
				RES[i] = C[++c];
		}
		else
		{
			if(c < cs)
				RES[i] = C[++c];
			else
				RES[i] = T[++t];
		}
	}
	FOR(i,1,N-1)
		if(!(RES[i]%3) && !(RES[i+1]%3))
			return;
	FOR(i,1,N)
	{
		printf("%d",RES[i]);
		if(i != N)
			printf(" ");
	}
	printf("\n");
	exit(0);
}
int main()
{
	solve();
	printf("IMPOSSIBLE\n");
	return 0;
}
