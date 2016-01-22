#include <iostream>
#include <stack>
#define FOR(i,a,b) for(i=a; i<=b; i++)
using namespace std;
stack <int> st[15];
int N,P;
void solve()
{
	int a,b,i,s=0;
	scanf("%d %d",&N,&P);
	FOR(i,1,N)
	{
		scanf("%d %d",&a,&b);
		while(st[a].size() && st[a].top() > b)
		{
			s++;
			st[a].pop();
		}
		if(st[a].empty()) { st[a].push(b); s++; }
		else if(st[a].top() != b)
		{
			st[a].push(b);
			s++;
		}
	}
	printf("%d\n",s);
}
int main()
{
	solve();
	return 0;
}
