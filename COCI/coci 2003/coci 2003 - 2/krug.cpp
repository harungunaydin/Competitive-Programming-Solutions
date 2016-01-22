#include <iostream>
#define f first
#define s second
#define FOR(i,a,b) for(i=a; i<=b; i++)
using namespace std;
pair <int,int> p[100005];
void solve()
{
	int N,i,top=0;
	cin >> N;
	FOR(i,1,N)
	{
		cin >> p[i].f;
		p[i].s=i;
	}
	sort(p+1,p+N+1);
	FOR(i,1,N-1)
		if(p[i].s>p[i+1].s)
			top++;
	cout << top << endl;
}
int main()
{
	solve();
	return 0;
}
