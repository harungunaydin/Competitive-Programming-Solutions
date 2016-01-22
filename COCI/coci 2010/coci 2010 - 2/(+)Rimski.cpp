#include <iostream>
#include <cstdio>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
using namespace std;
void solve()
{
	string str,res = "";
	cin >> str;
	int i,t=str.size()-1;
	if(str[0] == 'L' && str[1] == 'X' && str[2] != 'X')
		swap(str[0],str[1]);
	if(str[t] == 'I' && str[t-1] == 'V')
		swap(str[t],str[t-1]);
	if(str[t] == 'I' && str[t-1] == 'X')
		swap(str[t],str[t-1]);
	if(str[0] == 'L' && str[1] == 'X' && str[2] != 'X')
		swap(str[0],str[1]);
	cout << str << endl;
}
int main()
{
	solve();
	return 0;
}
