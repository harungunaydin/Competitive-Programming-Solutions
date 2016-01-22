#include <iostream>
#include <cstdio>
#include <set>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define all(x) x.begin(),x.end()
#define MAXN 100
using namespace std;
set < int > res;
set < int > st[MAXN+5];
int A[MAXN+5];
void solve()
{
	set < int > :: iterator it;
	int E,N,i,j,k,s(0),t;
	bool flag;
	scanf("%d",&N);
	scanf("%d",&E);
	FOR(i,1,E)
	{
		scanf("%d",&t);
		flag = false;
		FOR(j,1,t)
		{
			scanf("%d",A+j);
			if(A[j] == 1) flag = true;
		}
		if(flag)
		{
			s++;
			FOR(j,1,t)
				st[A[j]].insert(s);
		}
		else
		{
			FOR(j,1,t)
				FOR(k,1,t)
						for(it = st[A[j]].begin(); it != st[A[j]].end(); ++it)
							st[A[k]].insert(*it);
		}
	}
	FOR(i,1,N)
		if(st[i].size() == s)
			res.insert(i);
	for(it = res.begin(); it != res.end(); ++it)
		printf("%d\n",*it);
}
int main()
{
	solve();
	return 0;
}
