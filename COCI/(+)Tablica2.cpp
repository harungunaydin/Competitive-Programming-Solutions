#include <iostream>
#include <cstdio>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define f first
#define s second
#define MAXN 1000
using namespace std;
typedef pair < int , int > pii;
pii B[MAXN+5],pos[MAXN+5];
int A[MAXN+5];
int M,N,K;
void satir(int sat,int s)
{
	int i;
	FOR(i,1,K)
		if(pos[i].f == sat)
			pos[i].s = (pos[i].s + s) % N;
}
void sutun(int sut,int s)
{
	int i;
	FOR(i,1,K)
		if(pos[i].s == sut)
			pos[i].f = (pos[i].f + s) % N;
}
void solve()
{
	int i,sat,sut;
	scanf("%d %d",&N,&K);
	FOR(i,1,K)
	{
		scanf("%d %d %d",A+i,&B[i].f,&B[i].s);
		A[i]--;
		B[i].f--;
		B[i].s--;
		pos[i] = make_pair ( A[i]/N , A[i]%N );
	}
	FOR(i,1,K)
	{
		sat = B[i].f - pos[i].f;
		sut = B[i].s - pos[i].s;
		if(sat < 0) sat+=N;
		if(sut < 0) sut+=N;
		printf("%d\n",sat + sut);
		satir(pos[i].f,sut);
		sutun(pos[i].s,sat);
	}
}
int main()
{
	solve();
	return 0;
}
