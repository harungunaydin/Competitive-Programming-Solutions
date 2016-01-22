#include <iostream>
#include <cstdio>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define MAXN 100
using namespace std;
int K,M,N,X;
int C[MAXN+5];
bool dene()
{
	int i,s(K);
	FOR(i,1,M-1)
		switch(C[i])
		{
			case 1 : s+=K; break;
			case 2 : s-=K; break;
			case 3 : s*=K; break;
			case 4 : s/=K; break;
			case 5 : s=s*10+s; break;
			default : break;
		}
	return s == X;
}
bool rec(int x)
{
	if(x == M) return dene();
	int i,t;
	FOR(i,1,5)
	{
		C[x] = i;
		t = rec(x+1);
		if(t) return 1;
	}
	return 0;
}
void solve()
{
	int i,j;
	scanf("%d",&K);
	scanf("%d",&N);
	FOR(i,1,N)
	{
		scanf("%d",&X);
		if(X == K) { printf("1\n"); continue; }
		FOR(M,2,8)
			if(rec(1))
				break;
		(M < 9) ? printf("%d\n",M) : printf("NIE\n");
	}
}
int main()
{
	solve();
	return 0;
}
