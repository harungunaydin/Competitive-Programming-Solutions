#include <iostream>
#include <algorithm>
#include <cstdio>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define TFOR(i,a,b) for(i=a; i>=b; i--)
#define MAXN 1000005
using namespace std;
int N,a,b;
int A[MAXN];
bool control(int x)
{
	int i,s(0);
	FOR(i,1,N-b+1)
		if(A[i+b-1] - A[i] <= x)
		{
			if(++s == a) return true;
			i = i + b - 1;
		}
	return false;
}
int BS(int bas,int son)
{
	if(bas == son) return bas;
	int orta = ( bas + son ) / 2;
	return control(orta) ? BS(bas,orta) : BS(orta+1,son);
}
void solve()
{
	int i;
	scanf("%d %d %d",&N,&a,&b);
	FOR(i,1,N) scanf("%d",A+i);
	sort(A+1,A+N+1);
	printf("%d\n" , BS(0,1000000000) );
}
int main()
{
	solve();
	return 0;
}
