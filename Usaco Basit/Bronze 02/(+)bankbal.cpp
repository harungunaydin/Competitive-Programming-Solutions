//SORU 446
//PROGRAM C++
#include <iostream>
#include <fstream>
#include <map>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define INPUT "bankbal.in"
#define OUTPUT "bankbal.out"
using namespace std;
ifstream in(INPUT);
ofstream out(OUTPUT);
map <string,int> mp;
map <string,int> :: iterator it;
int N;
void solve()
{
	string str;
	int a,i;
	in >> N;
	FOR(i,1,N)
	{
		in >> str;
		in >> a;
		mp[str]+=a;
	}
	out << "Alice " << mp["Alice"] << endl;
	out << "Betsy " << mp["Betsy"] << endl;
	out << "Corinne " << mp["Corinne"] << endl;
	out << "Debra " << mp["Debra"] << endl;
}
int main()
{
	solve();
	return 0;
}
