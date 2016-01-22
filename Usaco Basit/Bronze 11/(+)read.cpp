//SORU 932
//PROGRAM C++
#include <iostream>
#include <fstream>
#include <cmath>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define all(x) x.begin(),x.end()
#define INPUT "read.in"
#define OUTPUT "read.out"
using namespace std;
ifstream in(INPUT);
ofstream out(OUTPUT);
void solve()
{
	int K,N,a,b,c,e,i,s;
	double d,k;
	in >> N >> K;
	FOR(i,1,K)
	{
		in >> a >> b >> c;
		d = e = s = 0;
		while(1)
		{
			if(s + a >= N)
			{
				d+=double(N - s) / a;
				break;
			}
			s+=a;
			d++;
			if(++e == b)
			{
				e = 0;
				d+=c;
			}
		}
		out << ceil(d) << endl;
	}
}
int main()
{
	solve();
	return 0;
}
