#include <iostream>
#include <cstdio>
#include <cstring>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define MAXN 200005
using namespace std;
typedef pair < int , int > pii;
int N,Q;
int A[MAXN],F[MAXN];
void update(int x)
{
	for(; x < MAXN; x += x&-x)
		F[x]++;
}
int find(int x)
{
	int res(0);
	for(; x; x -= x&-x)
		res += F[x];
	return res;
}
int BS(int bas,int son,int a)
{
	if(bas == son) return bas;
	int orta = ( bas + son ) / 2;
	return orta - find(orta) >= a ? BS(bas,orta,a) : BS(orta+1,son,a);
}
void solve()
{
	int a,i,s,t;
	char c;
	memset( F , 0 , sizeof F );
	scanf("%d %d",&N,&Q);
	FOR(i,1,N) scanf("%d",A+i);
	s = N;
	FOR(i,1,Q)
	{
		scanf(" %c %d",&c,&a);
		if(c == 'a') { A[++N] = a; s++; }
		else
		{
			if(a > s) { printf("none\n"); continue; }
			s--;
			t = BS(1,N,a);
			printf("%d\n" , A[t] );
			update(t);
		}
	}
}
int main()
{
	int T,i;
	scanf("%d",&T);
	FOR(i,1,T)
	{
		printf("Case %d:\n",i);
		solve();
	}
	return 0;
}
