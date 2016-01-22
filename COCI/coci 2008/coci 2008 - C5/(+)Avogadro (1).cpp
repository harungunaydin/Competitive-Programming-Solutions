#include <iostream>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define f first
#define s second
#define MAXN 100005
using namespace std;
pair < pair < int , int > , int > A[MAXN+5];
int N;
int B[4][MAXN+5];
bool deleted[MAXN+5];
void rec(int x,int d)
{
	if(d > N+1) return;
	if(x == N + 1) return;
	if(!deleted[x] && (!B[1][x] || !B[2][x]))
	{
			deleted[x] = true;
			B[1][A[x].f.s]--;
			B[2][A[x].s]--;
			if(A[x].f.s < x && !deleted[A[x].f.s])
				rec(A[x].f.s,d+1);
			if(A[x].s < x && !deleted[A[x].s])
				rec(A[x].s,d+1);
	}
	rec(x+1,d+1);
}
void solve()
{
	int i,s(0);
	scanf("%d",&N);
	FOR(i,1,N)
	{
		scanf("%d",&A[i].f.f);
		B[0][A[i].f.f]++;
	}
	FOR(i,1,N)
	{
		scanf("%d",&A[i].f.s);
		B[1][A[i].f.s]++;
	}
	FOR(i,1,N)
	{
		scanf("%d",&A[i].s);
		B[2][A[i].s]++;
	}
	sort(A+1,A+N+1);
	rec(1,0);
	FOR(i,1,N)
		s+=deleted[i];
	printf("%d\n",s);
}
int main()
{
	solve();
	return 0;
}
