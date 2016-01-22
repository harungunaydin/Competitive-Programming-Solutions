#include <algorithm>
#include <cstdio>
#include <iostream>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define TFOR(i,a,b) for(i=a; i>=b; i--)
#define all(x) x.begin(),x.end()
using namespace std;
string cevir( string str , char c1 , char c2 )
{
	for(int i = 0; i < (int) str.size(); i++)
		if(str[i] == c1)
			str[i] = c2;
	return str;
}
int stoi(string str)
{
	int t(0) , i;
	for(i = 0; i < (int) str.size(); i++)
		t = t * 10 + str[i] - '0';
	return t;
}
void solve()
{
	string str,str2;
	cin >> str >> str2;

	str = cevir(str,'6','5');
	str2 = cevir(str2,'6','5');

	printf("%d " , stoi(str) + stoi(str2) );

	str = cevir(str,'5','6');
	str2 = cevir(str2,'5','6');

	printf("%d\n" , stoi(str) + stoi(str2) );

}
int main()
{
	solve();
	return 0;
}
