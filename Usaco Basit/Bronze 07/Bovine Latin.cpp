//SORU 521
//PROGRAM C++
#include <iostream>
#include <fstream>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define INPUT "latin.in"
#define OUTPUT "latin.out"
#define IS_VOVEL(x) (x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u')
using namespace std;
ifstream in(INPUT);
ofstream out(OUTPUT);
int N;
void solve()
{
	int i;
	in >> N;
	string str;
	FOR(i,1,N)
	{
		in >> str;
		if(IS_VOVEL(str[0]))
			out << str + "cow" << endl;
		else
			out << str.substr(1) + str[0] + "ow" << endl;
	}
}
int main()
{
	solve();
	return 0;
}
