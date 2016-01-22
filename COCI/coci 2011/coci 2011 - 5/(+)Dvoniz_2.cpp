#include <iostream>
#include <cstdio>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define MAXN 1000000
using namespace std;
long long N,S,i;
long long A[MAXN+5];
bool kontrol(int bas,int uz)
{
	long long a = A[bas+uz-1] - A[bas-1];
	long long b = A[bas+2*uz-1] - A[bas+uz-1];
	return a <= S && b <= S;
}
long long BS(long long bas,long long son)
{
	long long orta = (bas + son)/2;
	if(bas == son) return (kontrol(i,bas)) ? 2*bas : 0;
	if(bas+1 == son)
	{
		if(kontrol(i,son)) return son*2;
		if(kontrol(i,bas)) return bas*2;
		return 0;
	}
	if(kontrol(i,orta)) return BS(orta,son);
	if(A[i+orta-1] - A[i-1] > S) return BS(bas,orta);
	return (kontrol(i,bas)) ? max(bas*2,BS(bas+1,son)) : BS(bas+1,son);
}
void solve()
{
	scanf("%lld %lld",&N,&S);
	FOR(i,1,N)
	{
		scanf("%lld",A+i);
		A[i]+=A[i-1];
	}
	FOR(i,1,N)
		printf("%d\n",BS(1,(N-i+1)/2));
}
int main()
{
	solve();
	return 0;
}
