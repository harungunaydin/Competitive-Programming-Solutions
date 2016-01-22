//SORU 348
//PROGRAM C++
#include <iostream>
#include <fstream>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define INPUT "calfnum.in"
#define OUTPUT "calfnum.out"
using namespace std;
ifstream in(INPUT);
ofstream out(OUTPUT);
int A[200];
string strs[] = {"no","pa","re","ci","vo","mu","xa","ze","bi","so"};
long long to_int_from_str(string str)
{
	long long i,t=0,x=1;
	for(i=0; i<str.size()-2; i+=2,x*=10);
	for(i=0; i<str.size(); i+=2,x/=10)
		t+=A[str[i]]*x;
	return t;
}
void print(long long x)
{
	if(!x) return;
	print(x/10);
	out << strs[x%10];
}
void solve()
{
	long long i,j,s=0;
	string str;
	FOR(i,1,6)
	{
		getline(in,str);
		for(string :: iterator it = str.begin(); it!=str.end(); ++it)
			if(*it == ' ')
				str.erase(it);
		s+=to_int_from_str(str);
	}
	print(s);
}
int main()
{
	A['p'] = 1; A['r'] = 2; A['c'] = 3;
	A['v'] = 4; A['m'] = 5; A['x'] = 6;
	A['z'] = 7; A['b'] = 8; A['s'] = 9;
	solve();
	return 0;
}
