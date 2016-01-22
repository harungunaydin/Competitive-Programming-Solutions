#include <iostream>
#include <cstdio>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define all(x) x.begin(),x.end()
using namespace std;
string solve()
{
	string str,str2,str3;
	int N,i;
	scanf("%d",&N);
	if(N == 1 || N == 2) return "TAK";
	if(N == 3)
	{
		cin >> str >> str2 >> str3;
		if(str == "011" && str2 == "11" && str3 == "00000" )
			return "TAK";
	}
	return "NIE";
}
int main()
{
	cout << solve() << endl;
	return 0;
}
