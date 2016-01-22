#include <iostream>
#include <cstdio>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
using namespace std;
int aylar[15] = {0,31,29,31,30,31,30,31,31,30,31,30,31};
bool artik(int yil)
{
	yil+=(yil < 600) ? 2000 : 1000;
	if(!(yil%400)) return 1;
	if(!(yil%100)) return 0;
	return !(yil%4);
}
bool solve()
{
	string str;
	cin >> str;
	int gun = (str[0] - '0') * 10 + (str[1] - '0');
	int ay =  (str[2] - '0') * 10 + (str[3] - '0');
	int yil = (str[4] - '0') * 100 + (str[5] - '0') * 10 + (str[6] - '0');
	int author = (str[7] - '0');
	if(gun < 1 || gun > 31) return 0;
	if(ay < 1 || ay > 12) return 0;
	if(gun > aylar[ay]) return 0;
	if(gun == 29 && ay == 2 && !artik(yil)) return 0;
	if(author != 1 && author != 6 && author != 9) return 0;
	int i,s(0);
	FOR2(i,8)
		s+=(str[i] - '0') * (str[i] - '0');
	return s%7 == str[8] - '0';
}
int main()
{
	cout << solve() << endl;
	cout << solve() << endl;
	cout << solve() << endl;
	return 0;
}
