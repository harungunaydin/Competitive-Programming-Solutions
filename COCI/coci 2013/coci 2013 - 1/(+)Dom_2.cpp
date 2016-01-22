#include <iostream>
#include <cstdio>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
using namespace std;
bool H[300];
void solve()
{
	string str = "CAMBRIDGE";
	int i;
	FOR2(i,str.size()) H[str[i]] = true;
	cin >> str;
	FOR2(i,str.size())
		if(!H[str[i]])
			printf("%c",str[i]);
}
int main()
{
	solve();
	return 0;
}
