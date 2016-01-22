#include <iostream>
#include <cstdio>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define INF 2000000000
#define MAXN 100
using namespace std;
int M,N;
class porsiyon
{
	public:
		int X,Y,sm,pm,sv,pv;

}A[MAXN+5];
int hesapla(int x,int a)
{
	int i(0),res(INF),t;
	while(1)
	{
		t = ((a*A[x].X - i*A[x].sv - A[x].Y + A[x].sm - 1)/A[x].sm );
		if(t < 0) break;
		res = min( res , t * A[x].pm + i * A[x].pv );
		if((++i)*A[x].pv > M) break;
	}
	return res;
}
bool kontrol(int a)
{
	int i,s(M);
	FOR(i,1,N)
	{
		s-=hesapla(i,a);
		if(s < 0)
			return 0;
	}
	return 1;
}
int BS(int bas,int son)
{
	int orta = (bas + son)/2;
	if(bas+1 == son) return kontrol(son) ? son : kontrol(bas) ? bas : 0;
	if(bas == son) return kontrol(bas) ? bas : 0;
	return kontrol(orta) ? max(orta,BS(orta+1,son)) : BS(bas,orta-1);
}
void solve()
{
	int i;
	scanf("%d %d",&N,&M);
	FOR(i,1,N)
		scanf("%d %d %d %d %d %d",&A[i].X,&A[i].Y,&A[i].sm,&A[i].pm,&A[i].sv,&A[i].pv);
	printf("%d\n",BS(0,100000));
}
int main()
{
	solve();
	return 0;
}
