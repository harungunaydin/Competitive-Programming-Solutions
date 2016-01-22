#include <iostream>
#include <stack>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define f first
#define s second
#define mp(x,y) make_pair(x,y)
using namespace std;
typedef long long unsigned lli;
stack < pair <bool,lli> > st;
lli mod=123456789;
void solve()
{
	lli N,c,i,x,syc=0;
	cin >> N;
	FOR(i,1,N)
	{
		cin >> c;
		if(c)
		{
			x=st.top().s;
			st.pop();
			if(!st.empty())
			{
				st.top().s+=(x) ? 2*x : 1;
				st.top().s%=mod;
			}
			else
			{
				syc+=(x) ? 2*x : 1;
				syc%=mod;
			}
		}
		else
			st.push(mp(0,0));
	}
	cout << syc % mod << endl;
}
int main()
{
	mod*=100;
	mod+=10;
	solve();
	return 0;
}
