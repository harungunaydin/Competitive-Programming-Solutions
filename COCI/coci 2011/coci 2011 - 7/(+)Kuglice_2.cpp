#include <iostream>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define TFOR(i,a,b) for(i=a; i>=b; i--)
#define f first
#define s second
#define MAXN 300000
using namespace std;
pair <int,int> B[MAXN+5];
int A[MAXN+5],RES[MAXN+5],parent[MAXN+5];
int atabul(int x)
{
	if(parent[x] == x || parent[x] < 0) return x;
	return parent[x] = atabul(parent[x]);
}
void solve()
{
	int M,N,ata,i,n_res(0);
	scanf("%d",&N);
	FOR(i,1,N) parent[i] = -2;
	FOR(i,1,N)
	{
		scanf("%d",A+i);
		if(!A[i]) parent[i] = -1;
	}
	scanf("%d",&M);
	FOR(i,1,M)
	{
		scanf("%d %d",&B[i].f,&B[i].s);
		if(B[i].f == 2)
			parent[B[i].s] = -1;
	}
	TFOR(i,N,1)
		if(parent[i] == -2)
			parent[i] = atabul(A[i]);
	TFOR(i,M,1)
		if(B[i].f == 1)
		{
			ata = atabul(B[i].s);
			RES[n_res++] = (parent[ata] == -1) ? ata : -1;
		}
		else
			parent[B[i].s] = atabul(A[B[i].s]);
	TFOR(i,n_res-1,0)
		(RES[i] == -1) ? printf("CIKLUS\n") : printf("%d\n",RES[i]);
}
int main()
{
	solve();
	return 0;
}
