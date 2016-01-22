#include <iostream>
#define FOR(i,a,b) for(i=a; i<=b; i++)
using namespace std;
int DP[2005][2005];
string str,str2;
int solve(int x,int y)
{
	if(x==str.size()) return DP[x][y]=1000000;
	if(DP[x][y]) return DP[x][y];
	int i;
	for(i=y; i<str2.size(); i++)
		if(str[x]==str2[i])
			break;
	if(i==str2.size()) return DP[x][y]=1;
	return DP[x][y]=min(solve(x+1,i+1)+1,solve(x+1,y));
}
void print(int x,int y)
{
	if(x>=str.size()) return;
	if(DP[x][y]==DP[x+1][y]) { print(x+1,y); return; }
	cout << str[x];
	int i;
	for(i=y; i<str2.size(); i++)
		if(str[x]==str2[i])
			break;
	print(x+1,i+1);
}
int main()
{
	cin >> str >> str2;
	cout << solve(0,0) << endl;
	print(0,0);
	cout << endl;
	return 0;
}
