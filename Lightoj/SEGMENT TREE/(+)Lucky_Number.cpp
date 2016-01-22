#include <iostream>
#include <cstdio>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define MAXN 715005
using namespace std;
typedef pair < int , int > pii;
int N;
short A[MAXN],F[MAXN];
void update(int a)
{
	for(; a < MAXN; a += a&-a)
		F[a]++;
}
int find(int a)
{
	register int res(0);
	for(; a; a -= a&-a)
		res += F[a];
	return res;
}
int BS(int bas,int son,int a)
{
	if(bas == son) return bas;
	register int orta = ( bas + son ) / 2;
	return orta - find(orta) >= a ? BS(bas,orta,a) : BS(orta+1,son,a);
}
void hallet(int a)
{
	register int i,s(0),t = (BS(1,N,a) << 1) - 1;
	for(i = t; i <= N; i += t)
		A[++s] = BS(1,N,i);
	FOR(i,1,s)
		update(A[i]);
}
int main()
{
	N = 715000;
	register int T,a,i;
	FOR(i,2,9000) hallet(i);
	scanf("%d",&T);
	FOR(i,1,T)
	{
		printf("Case %d: ",i);
		scanf("%d",&a);
		printf("%d\n" , (BS(1,N,a) << 1) - 1);
	}
	return 0;
}
