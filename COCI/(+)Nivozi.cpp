#include <iostream>
#include <cstdio>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define MAXN 2000
using namespace std;
int N;
int A[MAXN+5],B[MAXN+5];
int DP[MAXN+5][MAXN+5];
inline int hesapla(int a,int b)
{
	register int res(0);
	if(DP[a][b] != -1) return DP[a][b];
	while(a <= b)
	{
		res+=A[a]*B[b];
		if(a != b)
			res+=A[b]*B[a];
		a++; b--;
	}
	return res;
}
void init()
{
	register int a,b,i,s;
	FOR2(i,N)
	{
		a = i-1;
		b = i+1;
		s = A[i]*B[i];
		while(a>=0 && b<N)
		{
			s+=A[a]*B[b] + A[b]* B[a];
			DP[a][b] = s;
			a--;
			b++;
		}
	}
}
void solve()
{
	register int i,j,k,res(0),resB,resE,t;
	scanf("%d",&N);
	FOR2(i,N)
		scanf("%d",A+i);
	FOR2(i,N)
		scanf("%d",B+i);
	FOR2(i,N)
		FOR2(j,N)
			DP[i][j] = -1;
	init();
	FOR(i,0,N)
		for(j=0; i+j<N; j++)
		{
			t = hesapla( i , N-j-1 );
			if(t > res)
			{
				res = t;
				resB = i;
				resE = j;
			}
		}
	printf("%d %d\n%d\n",resB,resE,res);
}
int main()
{
	solve();
	return 0;
}
