#include <iostream>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define f first
#define s second
#define MAXN 100
using namespace std;
typedef pair < int , int > pii;
pii A[MAXN+5],B[MAXN+5];
int M,N,T;
int hesapla1(int x)
{
	int i,s(0);
	FOR(i,1,N)
		if(x>=A[i].f)
			s+=(x-A[i].f)/A[i].s+1;
	return s;
}
int hesapla2(int x)
{
	int i,s(0);
	FOR(i,1,M)
		if(x>=B[i].f)
			s+=(x-B[i].f)/B[i].s+1;
	return s;
}
int BS(int bas,int son)
{
	if(bas == son) return bas;
	int orta = (bas + son) / 2;
	int a,b,c;
	a = hesapla1(orta);
	b = hesapla2(T-orta);
	c = hesapla2(T-orta-1);
	return (a == b || (c < a && a < b)) ? orta : (a < b) ? BS(orta+1,son) : BS(bas,orta-1);
}
void solve()
{
	int i;
	scanf("%d",&T);
	scanf("%d",&N);
	FOR(i,1,N)
		scanf("%d %d",&A[i].f,&A[i].s);
	scanf("%d",&M);
	FOR(i,1,M)
		scanf("%d %d",&B[i].f,&B[i].s);
	printf("%d\n",BS(1,T));
}
int main()
{
	solve();
	return 0;
}
