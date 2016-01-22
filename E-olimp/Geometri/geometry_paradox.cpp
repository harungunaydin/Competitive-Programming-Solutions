#include <iostream>
#include <cmath>
#include <sstream>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define all(x) x.begin(),x.end()
using namespace std;
const double PI = acos(-1);
void solve()
{
	int N,i,r1,r2;
	string str;
	cin >> N;
	getline(cin,str);
	FOR(i,1,N)
	{
		getline(cin,str);
		if(str.find(' ') == -1) { printf("Impossible.\n"); continue; }
		istringstream in(str);
		in >> r1 >> r2;
		printf("%.4lf\n",2*r1*r2*PI);
	}
}
int main()
{
	solve();
	return 0;
}
