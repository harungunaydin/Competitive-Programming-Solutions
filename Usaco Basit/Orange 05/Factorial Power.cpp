//SORU 356
//PROGRAM C++
#include <iostream>
#include <fstream>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define INPUT "fact.in"
#define OUTPUT "fact.out"
using namespace std;
ifstream in(INPUT);
ofstream out(OUTPUT);
int N;
void solve()
{
	int c=1,iki=0,i,bes=0;
	in >> N;
	FOR(i,2,N)
	{
		c*=i;
		while(!(c%2)) c/=2 , iki++;
		while(!(c%5)) c/=5 , bes++;
		c%=10;
	}
	FOR(i,1,iki-bes)
		c = (c*2)%10;
	out << c << " " << bes << endl;
}
int main()
{
	solve();
	return 0;
}
