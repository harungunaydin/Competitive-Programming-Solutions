#include <iostream>
#include <cstdio>
#include <algorithm>
#include <set>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define all(x) x.begin(),x.end()
#define MAXN 120000
using namespace std;
set < int > st[MAXN+5];
bool visited[MAXN+5];
set < int > rec(int x)
{
	if(!st[x].empty()) return st[x];
	set < int > a,b;
	a = rec(x/2);
	if(x&1)
	{
		b = rec(x/2+1);
		set_union(all(a),all(b),inserter(st[x],st[x].begin()));
		st[x].insert(x);
		return st[x];
	}
	else
	{
		st[x] = a;
		st[x].insert(x);
		return st[x];
	}
}
void hallet()
{
}
void solve()
{
	set < int > :: iterator it;
	register int N,i,t;
	st[1].insert(1);
	hallet();
	scanf("%d",&N);
	set < int > res = rec(N);
	for(it = res.begin(); it != res.end();)
	{
		printf("%d",*it);
		if(++it != res.end())
			printf(" ");
	}
	printf("\n");
}
int main()
{
	solve();
	return 0;
}
