//SORU 322
//PROGRAM C++
#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define INPUT "dictnum.in"
#define OUTPUT "dictnum.out"
#define all(x) x.begin(),x.end()
using namespace std;
ifstream in(INPUT);
ofstream out(OUTPUT);
vector < pair<string,int> > V;
string str[10] = {"zero","one","two","three","four","five","six","seven","eight","nine"};
int A,B;
string to_str_from_int(int x)
{
	string temp = "";
	while(x)
	{
		temp=str[x%10] + temp;
		x/=10;
	}
	return temp;
}
void solve()
{
	int i;
	in >> A >> B;
	FOR(i,A,B)
		V.push_back(make_pair( to_str_from_int(i),i));
	sort(all(V));
	out << V.begin()->second << " " << (V.end()-1)->second << endl;
}
int main()
{
	solve();
	return 0;
}
