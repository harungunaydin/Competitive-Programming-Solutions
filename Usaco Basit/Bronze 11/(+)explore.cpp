//SORU 931
//PROGRAM C++
#include <iostream>
#include <fstream>
#include <algorithm>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define all(x) x.begin(),x.end()
#define INPUT "explore.in"
#define OUTPUT "explore.out"
#define MAXN 50000
using namespace std;
ifstream in(INPUT);
ofstream out(OUTPUT);
int N,T;
int A[MAXN+5];
bool cmp(const int &a,const int &b)
{
	return abs(a) < abs(b);
}
void solve()
{
	int i,pos=0;
	in >> T >> N;
	FOR(i,1,N)
		in >> A[i];
	sort(A+1,A+N+1,cmp);
	FOR(i,1,N)
	{
		T-=abs(A[i]-pos);
		if(T < 0) break;
		pos = A[i];
	}
	out << i-1 << endl;
}
int main()
{
	solve();
	return 0;
}
