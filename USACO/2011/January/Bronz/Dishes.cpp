#include <iostream>
#include <stack>
#define FOR(i,a,b) for(i=a; i<=b; i++)
using namespace std;
stack <int> a1,a2,a3;
void solve()
{
	int N,i,j,x,y;
	scanf("%d",&N);
	for(i=N; i; i--)
		a1.push(i);
	while(1)
	{
		scanf("%d %d",&x,&y);
		if(x==1)
			FOR(j,1,y)
			{
				a2.push(a1.top());
				a1.pop();
				if(a1.empty()) break;
			}
		else
			FOR(j,1,y)
			{
				a3.push(a2.top());
				a2.pop();
				if(a1.empty() && a2.empty())
					return;
			}
	}
}
int main()
{
	solve();
	while(!a3.empty())
	{
		printf("%d\n",a3.top());
		a3.pop();
	}
	return 0;
}
