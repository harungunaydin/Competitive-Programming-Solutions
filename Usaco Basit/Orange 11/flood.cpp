//SORU 412
//PROGRAM C++
#include <iostream>
#include <fstream>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define all(x) x.begin(),x.end()
#define INPUT "flood.in"
#define OUTPUT "flood.out"
#define MAXN 10000
using namespace std;
ifstream in(INPUT);
ofstream out(OUTPUT);
int A[MAXN+5];
void solve()
{
	int M,N,V,a,i,h,res=0;
	in >> M >> N >> V;
	N*=M;
	FOR(i,1,N)
	{
		in >> a;
		A[a]++;
	}
	h = 1;
	while(!A[h]) h++;
	a = 0;
	while(V > 0)
	{
			res+=A[h]*h;
			a+=A[h++];
			V-=a;
	}
	out << h << " " << res+h*A[h] << endl;
}
int main()
{
	solve();
	return 0;
}
