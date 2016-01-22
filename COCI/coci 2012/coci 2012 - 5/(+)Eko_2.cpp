#include <iostream>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define all(x) x.begin(),x.end()
#define INF 2100000000
#define MAXN 1000000
using namespace std;
int N;
long long M;
long long A[MAXN+5];
long long hesapla(long long x)
{
	int i;
	long long s(0);
	FOR(i,1,N)
		if(x < A[i])
			s+=A[i]-x;
	return s;
}
int hallet(int a,int b)
{
	int a1 = hesapla(a);
	int b1 = hesapla(b);
	if(a1 < M && b1 < M) return -INF;
	return (b1 > M) ? b : a;
}
int BS(int bas,int son)
{
	int orta = (bas+son)/2;
	long long a = hesapla(orta);
	if(bas+1 == son) return hallet(bas,son);
	if(bas == son) return (a > M) ? bas : -INF;
	return (a == M) ? orta : (a > M) ? max(orta,BS(orta+1,son)) : BS(bas,orta-1);
}
void solve()
{
	long long i,maxi(0),mini(INF);
	scanf("%d %lld",&N,&M);
	FOR(i,1,N)
	{
		scanf("%lld",A+i);
		mini = min(mini,A[i]);
		maxi = max(maxi,A[i]);
	}
	printf("%d\n",BS(mini,maxi));
}
int main()
{
	solve();
	return 0;
}
