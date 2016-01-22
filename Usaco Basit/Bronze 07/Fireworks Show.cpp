//SORU 522
//PROGRAM C++
#include <iostream>
#include <fstream>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define INPUT "fireshow.in"
#define OUTPUT "fireshow.out"
#define MAXN 2000000
using namespace std;
ifstream in(INPUT);
ofstream out(OUTPUT);
int M,N;
bool A[MAXN+5];
void solve()
{
	int c,i,j,s=0;
	in >> M >> N;
	FOR(i,1,M)
	{
		in >> c;
		for(j=c; j<=N; j+=c)
		{
			if(!A[j])
				s++;
			A[j] = true;
		}
	}
	out << s << endl;
}
int main()
{
	solve();
	return 0;
}
