//SORU 374
//PROGRAM C++
#include <iostream>
#include <fstream>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define all(x) x.begin(),x.end()
#define INPUT "vhist.in"
#define OUTPUT "vhist.out"
#define MAXN 30
#define IS_ALPHABET(x) (x>='A' && x<='Z')
using namespace std;
ifstream in(INPUT);
ofstream out(OUTPUT);
int A[MAXN+5];
void solve()
{
	string str;
	int i,j,maxi=0;
	FOR2(i,4)
	{
		getline(in,str);
		for(j=0; j<str.size(); j++)
			if(IS_ALPHABET(str[j]))
				A[str[j]-'A']++;
	}
	FOR2(i,26)
		maxi = max(maxi,A[i]);
	for(i=maxi; i>0; i--,out << endl)
		FOR2(j,26)
			if(A[j] >= i)
				out << "* ";
			else
				out << "  ";
	FOR(i,'A','Z')
		out << char(i) << " ";
}
int main()
{
	solve();
	return 0;
}
