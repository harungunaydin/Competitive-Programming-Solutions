//SORU 456
//PROGRAM C++
#include <iostream>
#include <fstream>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define TFOR(i,a,b) for(i=a; i>=b; i--)
#define all(x) x.begin(),x.end()
#define INPUT "dna.in"
#define OUTPUT "dna.out"
#define MAXN 100
using namespace std;
ifstream in(INPUT);
ofstream out(OUTPUT);
string str[MAXN+5];
int N;
int calc(int x,int y)
{
	int i;
	TFOR(i,min(str[x].size(),str[y].size()),1)
		if(str[x].substr(str[x].size()-i) == str[y].substr(0,i))
			return i;
	return 0;
}
void solve()
{
	int i,j,res=0;
	in >> N;
	FOR(i,1,N)
		in >> str[i];
	FOR(i,1,N)
		FOR(j,1,N)
			if(i != j)
				res = max(res,calc(i,j));
	out << res << endl;
}
int main()
{
	solve();
	return 0;
}
