#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <vector>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define all(x) x.begin(),x.end()
#define MAXN 100005
#define INF 20000000
using namespace std;
typedef pair < int , int > pii;
inline int Min( int a , int b ) { return a < b ? a : b; }
vector < int > V[MAXN];
int M,N;
int A[MAXN],B[MAXN],ST[4*MAXN];
int init(int pos,int s,int e)
{
	if(s == e) return ST[pos] = A[s];
	int m = ( s + e ) / 2;
	return ST[pos] = Min( init(pos*2,s,m) , init(pos*2+1,m+1,e) );
}
int find(int pos,int s,int e,int a,int b)
{
	if(a <= s && e <= b) return ST[pos];
	if(a > e || b < s) return INF;
	int m = ( s + e ) / 2;
	return Min( find(pos*2,s,m,a,b) , find(pos*2+1,m+1,e,a,b) );
}
inline int hesapla(int bas,int son)
{
	if(bas == son) return ( A[bas-1] > A[bas] ) + ( A[bas+1] > A[bas] ) + (A[bas] != 0);
	if(bas > son) return 0;
	int a,b, i, s, x , t = find(1,1,N,bas,son);

	a = lower_bound(all(V[t]),bas) - V[t].begin();
	b = upper_bound(all(V[t]),son) - V[t].begin() - 1;
	s = hesapla(bas,V[t][a]-1) + hesapla(V[t][b]+1,son);

	FOR(i,a,b)
	{
		x = V[t][i];
		if(A[x-1] > A[x]) s++;
		if(A[x+1] > A[x]) s++;
		if(i != b) s += hesapla(x+1,V[t][i+1]-1);
	}
	return s + (t != 0);
}
void solve()
{
	int i,res(0);
	scanf("%d %d",&N,&M);
	FOR(i,1,N)
	{
		scanf("%d",A+i);
		A[i] = M - A[i];
		V[A[i]].push_back(i);
	}
	init(1,1,N);
	A[0] = A[N+1] = -1;
	res = hesapla(1,N);
	FOR(i,1,N)
	{
		scanf("%d",A+i);
		V[A[i]].clear();
	}
	FOR(i,1,N)
		V[A[i]].push_back(i);
	init(1,1,N);
	printf("%d\n" , res + hesapla(1,N) );
}
int main()
{
	solve();
	return 0;
}
