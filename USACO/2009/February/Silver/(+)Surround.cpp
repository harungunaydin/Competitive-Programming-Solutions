#include <iostream>
#include <cstdio>
#include <vector>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define TFOR(i,a,b) for(i=a; i>=b; i--)
#define MAXN 501
using namespace std;
inline int Min( int a , int b ) { return a < b ? a : b; }
vector < int > V[MAXN];
int N,S;
int B[MAXN];
int A[MAXN][MAXN];
bool hash[MAXN];
int hesapla(int a,int k)
{
	int mini(123123123);
	vector < int > :: iterator it;
	for(it = V[k].begin(); it != V[k].end(); ++it)
		mini = Min( mini , A[*it][a] );
	return mini;
}
int solve(int k)
{
	vector < int > :: iterator it;
	int i,mini,sum(0);
	FOR(i,1,S)
		if(i != k)
		{
			mini = 123123123;
			for(it = V[i].begin(); it != V[i].end(); ++it)
				mini = Min( mini , hesapla(*it,k) );
			sum += 2 * mini;
		}
	return sum;
}
void read()
{
	int a,b,i,j,res(123123123);
	scanf("%d",&N);
	FOR(i,1,N)
	{
		scanf("%d %d",&a,&b);
		if(!hash[a] && !hash[b])
		{
			V[++S].push_back(a);
			V[S].push_back(b);
			B[a] = B[b] = S;
		}
		if(hash[a] && hash[b]) continue;
		if(hash[a]) { V[B[a]].push_back(b); B[b] = B[a]; }
		if(hash[b]) { V[B[b]].push_back(a); B[a] = B[b]; }
		hash[a] = hash[b] = true;
	}
	FOR(i,1,N)
		FOR(j,1,N)
			scanf("%d",A[i]+j);
	FOR(i,1,S)
		res = Min( res , solve(i) );
	printf("%d\n" , res );
}
int main()
{
	read();
	return 0;
}
