#include <iostream>
#include <algorithm>
#include <cstdio>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define all(x) x.begin(),x.end()
#define MAXN 100000
using namespace std;
int K,N;
long long A[MAXN+5],B[MAXN+5];
bool control(int M)
{
	int i;
	long long s(0);
	FOR(i,1,M) B[i] = A[i];
	sort(B+1,B+M+1);
	FOR(i,1,M)
		if(B[i] > s + 1)
			return 0;
		else
			s+=B[i];
	return s >= K;
}
int BS(int bas , int son)
{
	if(bas == son) return control(bas) ? bas : -1;
	if(bas + 1 == son) return control(bas) ? bas : control(son) ? son : -1;
	int orta = (bas + son)/2;
	return control(orta) ? BS(bas,orta) : BS(orta+1,son);
}
void solve()
{
	int i;
	scanf("%d %d",&N,&K);
	FOR(i,1,N) scanf("%lld",A+i);
	printf("%d\n",BS(1,N));
}
int main()
{
	int T,i;
	scanf("%d",&T);
	FOR(i,1,T)
		solve();
	return 0;
}
