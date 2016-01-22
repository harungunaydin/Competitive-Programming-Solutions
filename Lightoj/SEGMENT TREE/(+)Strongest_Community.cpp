#include <iostream>
#include <cstdio>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define f first
#define s second
#define MAXN 400005
using namespace std;
typedef pair < int , int > pii;
inline int Max( int a , int b ) { return a > b ? a : b; }
pii P[MAXN];
int M,N,Q;
int A[MAXN],B[MAXN],C[MAXN],ST[MAXN];
int init(int pos,int s,int e)
{
	if(s == e) return ST[pos] = B[s];
	int m = ( s + e ) / 2;
	return ST[pos] = Max( init(pos*2,s,m) , init(pos*2+1,m+1,e) );
}
int find(int pos,int s,int e,int a,int b)
{
	if(a <= s && e <= b) return ST[pos];
	if(a > e || b < s) return 0;
	int m = ( s + e ) / 2;
	return Max( find(pos*2,s,m,a,b) , find(pos*2+1,m+1,e,a,b) );
}
void solve()
{
	M = 0;
	int a,b,c,i,j,res;
	scanf("%d %d %d",&N,&c,&Q);
	FOR(i,1,N)
		scanf("%d",A+i);
	FOR(i,1,N)
	{
		j = i;
		M++;
		while(i <= N && A[i] == A[j]) C[i++] = M;
		B[M] = i - j;
		i--;
	}
	FOR(i,1,M)
		P[i] = make_pair(P[i-1].s+1 , P[i-1].s + B[i] );
	init(1,1,M);
	FOR(i,1,Q)
	{
		scanf("%d %d",&a,&b);
		if(C[a] == C[b]) res = b - a + 1;
		else if(C[a] + 1 == C[b]) res = Max( P[C[a]].s - a + 1 , b - P[C[b]].f + 1 );
		else
		{
			res = find(1,1,M,C[a]+1,C[b]-1);
			res = Max( res , Max(P[C[a]].s - a + 1 , b - P[C[b]].f + 1) );
		}
		printf("%d\n" , res );
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
