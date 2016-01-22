#include <iostream>
#define FOR(i,a,b) for(i=a; i<=b; i++)
using namespace std;
int l1,l2;
int DP[1005][1005];
string str,str2;
int solve(int x,int y)
{
	if(x==l1) return DP[x][y]=1000000;
	if(DP[x][y]) return DP[x][y];
	int i;
	for(i=y; i<l2; i++)
		if(str[x]==str2[i])
			break;
	if(i==l2) return DP[x][y]=1;
	return DP[x][y]=min(solve(x+1,i+1)+1,solve(x+1,y));
}
int main()
{
	cin >> str >> str2;
	l1=str.size();
	l2=str2.size();
	cout << solve(0,0) << endl;
	return 0;
}
