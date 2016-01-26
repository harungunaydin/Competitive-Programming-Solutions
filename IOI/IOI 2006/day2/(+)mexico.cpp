#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define F(x) ( x == N ? 1 : x + 1 )
#define G(x) ( x == 1 ? N : x - 1 )
#define MAXN 1005
using namespace std;
typedef pair < int , int > pii;
vector < int > res;
int M,N,vis;
int visited[MAXN];
int A[MAXN][MAXN];
char DP[MAXN][MAXN][2];
void print()
{
	vector < int > :: iterator it;
	for(it = res.begin(); it != res.end(); ++it)
		printf("%d\n" , *it );
	exit(0);
}
char dp(int a,int b,bool k,int s);
void yol(int a,int b,bool k,int s)
{
	res.push_back( k ? b : a );
	if(s == N) print();
	if(a > b)
	{
		if(k)
		{
			if(A[b][F(b)] && dp(a,F(b),1,s+1)) yol(a,F(b),1,s+1);
			if(A[b][G(a)] && dp(G(a),b,0,s+1)) yol(G(a),b,0,s+1);
		}
		else
		{
			if(A[a][G(a)] && dp(G(a),b,0,s+1)) yol(G(a),b,0,s+1);
			if(A[a][F(b)] && dp(a,F(b),1,s+1)) yol(a,F(b),1,s+1);
		}
	}
	else
	{
		if(k)
		{
			if(A[b][F(b)] && dp(a,F(b),1,s+1)) yol(a,F(b),1,s+1);
			if(A[b][G(a)] && dp(G(a),b,0,s+1)) yol(G(a),b,0,s+1);
		}
		else
		{
			if(A[a][G(a)] && dp(G(a),b,0,s+1)) yol(G(a),b,0,s+1);
			if(A[a][F(b)] && dp(a,F(b),1,s+1)) yol(a,F(b),1,s+1);
		}
	}
}
char dp(int a,int b,bool k,int s)
{
	char &ret = DP[a][b][k];
	if(ret != -1) return ret;
	if(s == N) return ret = true;
	if(a > b)
	{
		if(k)
		{
			if(A[b][F(b)] && dp(a,F(b),1,s+1)) return ret = true;
			if(A[b][G(a)] && dp(G(a),b,0,s+1)) return ret = true;
		}
		else
		{
			if(A[a][G(a)] && dp(G(a),b,0,s+1)) return ret = true;
			if(A[a][F(b)] && dp(a,F(b),1,s+1)) return ret = true;
		}
	}
	else
	{
		if(k)
		{
			if(A[b][F(b)] && dp(a,F(b),1,s+1)) return ret = true;
			if(A[b][G(a)] && dp(G(a),b,0,s+1)) return ret = true;
		}
		else
		{
			if(A[a][G(a)] && dp(G(a),b,0,s+1)) return ret = true;
			if(A[a][F(b)] && dp(a,F(b),1,s+1)) return ret = true;
		}
	}
	return ret = false;
}
void solve()
{
	int a,b,i;
	scanf("%d %d",&N,&M);
	FOR(i,1,M)
	{
		scanf("%d %d",&a,&b);
		A[a][b] = A[b][a] = true;
	}
	memset( DP , -1 , sizeof DP );
	FOR(i,1,N)
		if(dp(i,i,0,1))
			yol(i,i,0,1);
	printf("-1\n");
}
int main()
{
	solve();
	return 0;
}
