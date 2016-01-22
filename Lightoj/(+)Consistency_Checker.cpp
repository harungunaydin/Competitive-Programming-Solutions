#include <iostream>
#include <cstdio>
#include <map>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define MAXN 10005
using namespace std;
map < int , bool > mp;
string str[MAXN];
char A[15];
int solve()
{
	mp.clear();
	int N,i,j,t,u;
	char c;
	scanf("%d",&N);
	FOR(i,1,N)
	{
		t = 0;
		scanf("%s",A);
		str[i] = A;
		for(j = 0; j < (int) str[i].size() - 1; j++)
		{
			t = t * 10 + A[j];
			mp[t] = true;
		}
	}
	FOR(i,1,N)
	{
		t = 0;
		FOR2(j,str[i].size())
			t = t * 10 + str[i][j];
		if(mp[t]) return false;
	}
	return true;
}
int main()
{
	int T,i;
	scanf("%d",&T);
	FOR(i,1,T)
	{
		printf("Case %d: ",i);
		solve() ? printf("YES\n") : printf("NO\n");
	}
	return 0;
}
