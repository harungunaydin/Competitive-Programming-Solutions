#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define RAKAM(x) ('0' <= x && x <= '9')
#define all(x) x.begin(),x.end()
using namespace std;
vector < string > V;
string str;
int N;
inline bool cmp( string a , string b )
{
	if(a.size() < b.size()) return 1;
	if(a.size() > b.size()) return 0;
	for(int i = 0; i < (int) a.size(); i++)
		if(a[i] < b[i])
			return 1;
		else if(a[i] > b[i])
			return 0;
	return 1;
}
int hallet(int a)
{
	int b = a , i;
	while(b < (int) str.size() && RAKAM(str[b])) b++;
	b--;
	string tmp = "";
	while(a < (int) str.size() && str[a] == '0') a++;
	if(a > b) { V.push_back("0"); return b; }
	FOR(i,a,b)
		tmp += str[i];
	V.push_back(tmp);
	return b;
}
void solve()
{
	int i;
	scanf("%d",&N);
	while(N--)
	{
		cin >> str;
		for(i = 0; i < (int) str.size(); i++)
			if(RAKAM(str[i]))
				i = hallet(i);
	}
	sort( all(V) , cmp );

	vector < string > :: iterator it;
	
	for(it = V.begin(); it != V.end(); ++it)
		cout << *it << endl;

}
int main()
{
	solve();
	return 0;
}
