#include <iostream>
#include <map>
#define FOR(i,a,b) for(i=a; i<=b; i++)
using namespace std;
map <string , bool> mp;
void solve()
{
	string str;
	int M,N,i,j,s(0);
	scanf("%d",&M);
	FOR(i,1,M)
	{
		cin >> str;
		mp[str] = true;
	}
	double t = M/2.0;
	scanf("%d",&N);
	FOR(i,1,N)
	{
		cin >> str;
		if(mp[str])
			++s,mp[str] = false;
		if(s >= t)
			break;
	}
	printf("%d\n",i);
}
int main()
{
	solve();
	return 0;
}
