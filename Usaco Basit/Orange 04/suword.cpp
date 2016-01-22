//SORU 343
//PROGRAM C++
#include <iostream>
#include <fstream>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define all(x) x.begin(),x.end()
#define INPUT "suword.in"
#define OUTPUT "suword.out"
#define MAXN 100
using namespace std;
ifstream in(INPUT);
ofstream out(OUTPUT);
string str[MAXN+5];
void solve()
{
	string temp,res;
	int N,i,j;
	in >> N;
	FOR(i,1,N)
		in >> str[i];
	res = str[1];
	FOR(i,1,N-1)
	{
		for(j = min(str[i].size(),str[i+1].size())-1; j>0; j--)
			if(str[i].substr(str[i].size()-j) == str[i+1].substr(0,j))
				break;
		res.resize(res.size()-j);
		res+=str[i+1];
	}
	out << res << endl;
}
int main()
{
	solve();
	return 0;
}
