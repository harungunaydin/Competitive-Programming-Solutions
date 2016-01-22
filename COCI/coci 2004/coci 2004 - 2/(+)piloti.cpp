#include <iostream>
#include <queue>
#define FOR(i,a,b) for(i=a; i<=b; i++)
using namespace std;
priority_queue <int> Q;
void solve()
{
	int a,b,i,N,fark,top=0;
	scanf("%d",&N);
	FOR(i,1,N)
	{
		scanf("%d %d",&a,&b);
		top+=a;
		Q.push(a-b);
		if(i&1)
		{
			top-=Q.top();
			Q.pop();
		}
	}
	cout << top << endl;;
}
int main()
{
	solve();
	return 0;
}
