#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define all(x) x.begin(),x.end()
#define BASE 10007ll
#define MAXN 10005
using namespace std;
typedef pair < int , int > pii;
vector < int > T[MAXN],T2[MAXN];
string str,str2;
int K,M,N,pos;
char A[MAXN],B[MAXN];
void generate1(int x)
{
	while(pos < K)
	{
		if(str[pos++] == '0') return;
		T[x].push_back(++M);
		generate1(M);
	}
}
void generate2(int x)
{
	while(pos < K)
	{
		if(str2[pos++] == '0') return;
		T2[x].push_back(++N);
		generate2(N);
	}
}
long long hash(vector < long long > V)
{
	sort(all(V));
	long long res(1);
	vector < long long > :: iterator it;
	for(it = V.begin(); it != V.end(); ++it)
		res = res * BASE + (*it);
	return res;
}
long long dfs1(int x)
{
	vector < long long > V;
	vector < int > :: iterator it;

	for(it = T[x].begin(); it != T[x].end(); ++it)
		V.push_back( dfs1(*it) );

	return hash(V);
}
long long dfs2(int x)
{
	vector < long long > V;
	vector < int > :: iterator it;

	for(it = T2[x].begin(); it != T2[x].end(); ++it)
		V.push_back( dfs2(*it) );
	
	return hash(V);
}
void solve()
{
	getline(cin,str);
	getline(cin,str2);

	K = str.size();
	M = N = 1;

	pos = 0;
	generate1(1);

	pos = 0;
	generate2(1);

	dfs1(1) == dfs2(1) ? printf("Same\n") : printf("Different\n");

	int i;

	FOR(i,1,N) T[i].clear();
	FOR(i,1,M) T2[i].clear();
}
int main()
{
	int T,i;
	scanf("%d ",&T);
	FOR(i,1,T)
	{
		printf("Case %d: ",i);
		solve();
	}
	return 0;
}
