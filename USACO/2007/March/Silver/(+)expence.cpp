#include <iostream>
#include <cstdio>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define MAXN 100005
using namespace std;
typedef pair < int , int > pii;
int K,N;
int A[MAXN];
bool control(int x)
{
	int i,k(1),t(0);
	FOR(i,1,N)
	{
		if(A[i] > x) return 0;
		if(t + A[i] <= x)
			t += A[i];
		else
		{
			t = A[i];
			k++;
		}
	}
	return k <= K;
}
int BS(int bas,int son)
{
	if(bas == son) return bas;
	if(bas + 1 == son) return control(bas) ? bas : son;
	int orta = (bas + son) / 2;
	return control(orta) ? BS(bas,orta) : BS(orta+1,son);
}
void solve()
{
	int i;
	scanf("%d %d",&N,&K);
	FOR(i,1,N) scanf("%d",A+i);
	printf("%d\n" , BS(1,1000000000) );
}
int main()
{
	solve();
	return 0;
}
