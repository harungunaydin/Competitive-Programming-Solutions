#include <iostream>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define all(x) x.begin(),x.end()
using namespace std;
void solve()
{
	int N,i,k(1),res(0),s(0);
	string str,temp="";
	cin >> str;
	N = str.size();
	for(i=str.size()-1; i>=0; i--)
	{
		res+=(str[i]-'0')*k;
		if(++s == 3) { temp+=char(res%8) + '0'; s = res = 0; k = 1; continue; }
		k*=2;
	}
	temp+=char(res%8) + '0';
	while(temp[temp.size()-1] == '0') temp.resize(temp.size()-1);
	reverse(all(temp));
	cout << temp << endl;
}
int main()
{
	solve();
	return 0;
}
