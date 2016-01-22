#include <iostream>
#include <climits>
using namespace std;
int DP[1000][1000];
string str;
int f(int x,int y)
{
	if(DP[x][y]) return DP[x][y];
	string temp=str.substr(x,y-x+1);
	reverse(temp.begin(),temp.end());
	if(temp==str.substr(x,y-x+1)) return 1;
	int i,mini=INT_MAX;
	for(i=x; i<y; i++)
		mini=min(mini,f(x,i)+f(i+1,y));
	return DP[x][y]=mini;
}
void solve()
{
	cin >> str;
	cout << f(0,str.size()-1) << endl;
}
int main()
{
	solve();
	return 0;
}
