#include <iostream>
#include <cstdio>
#include <cstring>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define MAXN 102
using namespace std;
inline short Abs( short a ) { return a > 0 ? a : -a; }
class human
{
	public:
		short a,b;
		bool k;
		human() { a = b = k = 0; }
		void read() { scanf("%hd %hd %hd",&a,&b,&k); }
}B[MAXN],C[MAXN];
short M,N,T;
short visited[MAXN];
bool A[MAXN][MAXN];
bool dfs(short x,short vis)
{
	if(x == T) return true;
	visited[x] = vis;
	register short i;
	FOR(i,0,T)
		if(A[x][i] && visited[i] != vis && dfs(i,vis))
		{
			A[x][i] = false;
			A[i][x] = true;
			return true;
		}
	return false;
}
void solve()
{

	memset( A , 0 , sizeof A );
	memset( visited , 0 , sizeof visited );
	register short i,j;
	scanf("%hd %hd",&M,&N);
	T = M + N + 1;
	FOR(i,1,M) B[i].read();
	FOR(i,1,N) C[i].read();
	FOR(i,1,M)
		FOR(j,1,N)
			if(Abs(B[i].a - C[j].a) <= 12 && Abs(B[i].b - C[j].b) <= 5 && B[i].k == C[j].k)
				A[i][M+j] = true;
	FOR(i,1,M)
		A[0][i] = true;
	FOR(i,1,N)
		A[M+i][T] = true;
	register short res(0),vis(0);
	while(dfs(0,++vis)) res++;
	printf("%d\n" , res );
}
int main()
{
	register short T,i;
	scanf("%hd",&T);
	FOR(i,1,T)
	{
		printf("Case %hd: ",i);
		solve();
	}
	return 0;
}
