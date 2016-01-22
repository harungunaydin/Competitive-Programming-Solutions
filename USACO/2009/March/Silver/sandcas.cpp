//SORU 1228
//PROGRAM C++
#include <iostream>
#include <fstream>
#include <algorithm>
#define FOR(i,a,b) for(i=a; i<=b; i++)
#define FOR2(i,n) FOR(i,0,n-1)
#define all(x) x.begin(),x.end()
#define INPUT "sandcas.in"
#define OUTPUT "sandcas.out"
#define MAXN 25000
using namespace std;
ifstream in(INPUT);
ofstream out(OUTPUT);
int A[MAXN+5],B[MAXN+5];
void solve()
{
	int N,X,Y,i,result=0;
	in >> N >> X >> Y;
	FOR(i,1,N)
		in >> A[i] >> B[i];
	sort(A+1,A+N+1);
	sort(B+1,B+N+1);
	FOR(i,1,N)
		if(A[i] > B[i])
			result+=(A[i]-B[i])*Y;
		else
			result+=(B[i]-A[i])*X;
	out << result << endl;
}
int main()
{
	solve();
	return 0;
}
