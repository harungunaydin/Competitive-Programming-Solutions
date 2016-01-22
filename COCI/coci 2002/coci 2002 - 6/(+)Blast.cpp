#include <iostream>
using namespace std;
int K;
int DP[5000][5000];
string str,str2;
int solve(int x,int y)
{
	if(DP[x][y]) return DP[x][y];
	if(x==str.size() && y==str2.size()) return DP[x][y]=0;
	if(x==str.size()) return DP[x][y]=solve(x,y+1)+K;
	if(y==str2.size()) return DP[x][y]=solve(x+1,y)+K;
	return DP[x][y]=min(solve(x+1,y)+K,min(solve(x,y+1)+K,solve(x+1,y+1)+abs(str[x]-str2[y])));
}
int main()
{
	cin >> str >> str2;
	cin >> K;
	cout << solve(0,0) << endl;
	return 0;
}
