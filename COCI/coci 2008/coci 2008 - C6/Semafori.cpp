#include <iostream>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define f first
#define s second
#define MAXN 10000
using namespace std;
pair < int , int > A[MAXN+5];
void solve()
{
	int N,L,a,b,c,i,k,s(0);
	scanf("%d %d",&N,&L);
	FOR(i,1,N)
	{
		scanf("%d %d %d",&a,&b,&c);
		A[a] = make_pair(b,c);
	}
	FOR(i,1,L)
	{
		s++;
		if(A[i].f)
		{
			k = s%(A[i].f + A[i].s);
			if(k < A[i].f) s+=A[i].f-k;
		}
	}
	printf("%d\n",s);
}
int main()
{
	solve();
	return 0;
}
