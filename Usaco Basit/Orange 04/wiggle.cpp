//SORU 344
//PROGRAM C++
#include <iostream>
#include <fstream>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define all(x) x.begin(),x.end()
#define INPUT "wiggle.in"
#define OUTPUT "wiggle.out"
using namespace std;
ifstream in(INPUT);
ofstream out(OUTPUT);
int solve()
{
	string str;
	int i,j;
	in >> str;
	if(str.size() == 1) return 1;
	FOR(i,1,str.size()-1)
		if(!(str[i] - str[i-1]) || (str[i] - str[i-1] < 0 ) == (str[i+1] - str[i] < 0))
			break;
	if(i == 1) i = 0;
	return min(i+1,(int)str.size());
}
int main()
{
	out << solve() << endl;
	return 0;
}
