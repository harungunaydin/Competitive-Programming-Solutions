#include <iostream>
#define FOR(i,a,b) for(i=a; i<=b; i++)
using namespace std;
string str[10000][2];
string result[10000];
void solve()
{
	int i,N,son,bas;
	cin >> N;
	FOR(i,1,N)
	{
		cin >> str[i][0] >> str[i][1];
		if(str[i][1]=="SAME")
			result[i]=str[i][0];
	}
	son=N;
	bas=1;
	FOR(i,1,N)
	{
		while(result[bas]!="") bas++;
		if(str[i][1]=="DOWN") result[bas]=str[i][0];
		
	}
	for(i=N; i; i--)
	{
		while(result[son]!="") son--;
		if(str[i][1]=="UP") result[son]=str[i][0];
		
	}
	FOR(i,1,N)
		cout << result[i] << endl;
}
int main()
{
	solve();
	return 0;
}
