#include <iostream>
#include <map>
#define FOR(i,a,b) for(i=a; i<=b; i++)
using namespace std;
map <string,int> mp;
string str[10000];
void solve()
{
	int i,j,N,s=0;
	string temp;
	cin >> N;
	FOR(i,1,N)
	{
		cin >> temp;
		mp[temp]=i;
	}
	FOR(i,1,N)
		cin >> str[i];
	FOR(i,1,N)
		FOR(j,i+1,N)
			if(mp[str[j]]<mp[str[i]])
			{
				s++;
				break;
			}
	cout << s << endl;
}
int main()
{
	solve();
	return 0;
}
