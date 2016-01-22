#include <iostream>
#include <algorithm>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define all(x) x.begin(),x.end()
using namespace std;
string str;
string hesapla(int x,int y)
{
	string temp,temp2,temp3;
	temp = str.substr(0,x);
	reverse(all(temp));
	temp2 = str.substr(x,y-x);
	reverse(all(temp2));
	temp3 = str.substr(y);
	reverse(all(temp3));
	return temp + temp2 + temp3;
}
void solve()
{
	string res,t;
	int i,j;
	cin >> str;
	FOR(i,1,str.size()-1)
		FOR(j,i+1,str.size()-1)
		{
			t = hesapla(i,j);
			if(res.empty() || t < res) res = t;
		}
	cout << res << endl;
}
int main()
{
	solve();
	return 0;
}
