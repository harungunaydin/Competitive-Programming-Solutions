#include <iostream>
#include <algorithm>
#include <cstdio>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define f first
#define s second
#define MAXN 205
#define MAXL 10005
using namespace std;
inline int Min( int a , int b ) { return a < b ? a : b; }
typedef pair < int , int > pii;
pii A[MAXN];
int N,T;
int B[MAXN],X[MAXN],Y[MAXN];
void read()
{
	int i;
	while(scanf("%d",&B[++N]) != -1);
	N /= 2;
	FOR(i,1,N) X[i] = B[i];
	FOR(i,N+1,2*N) Y[i-N] = B[i];
	FOR(i,1,N) A[i] = make_pair(X[i]+1,Y[i]+1);
}
void solve()
{
	int bas,i,j,k,l,res(1000000000),y1,y2,s,t,son;
	sort(A+1,A+N+1);
	T = N / 2;
	FOR(i,1,N)
		FOR(j,1,N)
		{
			y1 = A[i].s + 1;
			y2 = A[j].s - 1;
			if(y1 <= y2) continue;

			s = 0;
			FOR(k,1,N)
				if(y2 < A[k].s && A[k].s < y1)
					B[++s] = A[k].f;
			FOR(k,1,s-T+1)
				res = Min( res , (y1 - y2) * (B[k+T-1] - B[k] + 2 ) );
		}
	if(res == 1000000000) res = 4;
	printf("%d\n" , res );
}
int main()
{
	read();
	solve();
	return 0;
}
