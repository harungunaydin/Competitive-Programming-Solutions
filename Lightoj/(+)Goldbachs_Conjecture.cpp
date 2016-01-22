#include <cstdio>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define MAXN 4999995
using namespace std;
int K;
int B[664580];
bool ASAL[MAXN];
void asallariBul(int N)
{
	int i,j;
	for(i = 3; i <= 3137; i+=2)
		if(!ASAL[i>>1])
			for(j = i * i; j <= N; j += 2 * i)
				ASAL[j>>1] = true;
	B[++K] = 2;
	for(i = 3; i <= N; i+=2)
		if(!ASAL[i>>1])
			B[++K] = i;
}
void solve()
{
	int N,i,k,res(0),t;
	scanf("%d",&N);
	t = N >> 1;
	for(i = 1; B[i] <= t; i++)
	{
		k = (N - B[i]);
		if((k&1) && !ASAL[k>>1])
			res++;
	}
	printf("%d\n" , res + (N == 4) );
}
int main()
{
	asallariBul(10000000);
	int T,i;
	scanf("%d",&T);
	FOR(i,1,T)
	{
		printf("Case %d: ",i);
		solve();
	}
	return 0;
}
